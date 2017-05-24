using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MathNet.Numerics.LinearAlgebra;
using MathNet.Numerics.LinearAlgebra.Double;

namespace Gamma4RTD
{
    class GaussNewtonSolver
    {
        /// <summary>
        ///   Fitting a power function like, y = a * x ^ b.
        /// </summary>
        /// <param name="guess">A guess for a and b.</param>
        /// <param name="pointCount">Number of data points.</param>
        /// <param name="dataX">X-coordinates of the data points.</param>
        /// <param name="dataY">Y-coordinates of the data points.</param>
        /// <returns>The power value for this fitting.</returns>
        public double Fit(
            double[] guess,
            int pointCount,
            Vector<double> dataX,
            Vector<double> dataY)
        {
            int n = guess.Length;
            int iterationsCount = 0;

            Vector<double> parametersCurrent = new DenseVector(guess);
            Vector<double> parametersNew = new DenseVector(n);

            double valueCurrent;
            double valueNew;

            GetObjectiveValue(
                pointCount,
                dataX,
                dataY,
                parametersCurrent,
                out valueCurrent);

            while (true)
            {
                Matrix<double> jacobian = new DenseMatrix(pointCount, n);
                Vector<double> residual = new DenseVector(pointCount);

                GetObjectiveJacobian(
                    pointCount,
                    dataX,
                    dataY,
                    parametersCurrent,
                    ref jacobian);

                GetResidualVector(
                    pointCount,
                    dataX,
                    dataY,
                    parametersCurrent,
                    ref residual);

                Vector<double> step = jacobian.Transpose().Multiply(jacobian).Cholesky().Solve(jacobian.Transpose().Multiply(residual));

                parametersCurrent.Subtract(step, parametersNew);

                GetObjectiveValue(
                    pointCount,
                    dataX,
                    dataY,
                    parametersNew,
                    out valueNew);

                iterationsCount++;

                if (ShouldTerminate(
                    valueCurrent,
                    valueNew,
                    iterationsCount,
                    parametersCurrent,
                    parametersNew))
                {
                    break;
                }

                parametersNew.CopyTo(parametersCurrent);
                valueCurrent = valueNew;
            }

            return parametersNew[1];
        }

        private bool ShouldTerminate(
            double valueCurrent,
            double valueNew,
            int iterationCount,
            Vector<double> parametersCurrent,
            Vector<double> parametersNew)
        {
            double MinimumDeltaValue = 0.0001;
            double MinimumDeltaParameters = 0.0001;
            double MaximumIterations = 50;

            return (
                       Math.Abs(valueNew - valueCurrent) <= MinimumDeltaValue ||
                       parametersNew.Subtract(parametersCurrent).Norm(2.0) <= MinimumDeltaParameters ||
                       iterationCount >= MaximumIterations);
        }

        /// <summary>
        ///   Get value of the objective function.
        /// </summary>
        /// <param name = "pointCount">Number of data points.</param>
        /// <param name = "dataX">X-coordinates of the data points.</param>
        /// <param name = "dataY">Y-coordinates of the data points.</param>
        /// <param name = "parameters">Model function parameters.</param>
        /// <param name = "value">Objective function value.</param>
        private void GetObjectiveValue(
            int pointCount,
            Vector<double> dataX,
            Vector<double> dataY,
            Vector<double> parameters,
            out double value)
        {
            value = 0.0;

            double y = 0.0;

            for (int j = 0; j < pointCount; j++)
            {
                GetValue(
                    dataX[j],
                    parameters,
                    out y);

                value += Math.Pow(
                    y - dataY[j],
                    2.0);
            }

            value *= 0.5;
        }

        /// <summary>
        ///   Get Jacobian matrix of the objective function.
        /// </summary>
        /// <param name = "pointCount">Number of data points.</param>
        /// <param name = "dataX">X-coordinates of the data points.</param>
        /// <param name = "dataY">Y-coordinates of the data points.</param>
        /// <param name = "parameters">Model function parameters.</param>
        /// <param name = "jacobian">Jacobian matrix of the objective function.</param>
        private void GetObjectiveJacobian(
            int pointCount,
            Vector<double> dataX,
            Vector<double> dataY,
            Vector<double> parameters,
            ref Matrix<double> jacobian)
        {
            int parameterCount = parameters.Count;

            // fill rows of the Jacobian matrix
            // j-th row of a Jacobian is the gradient of model function in j-th measurement
            for (int j = 0; j < pointCount; j++)
            {
                Vector<double> gradient = new DenseVector(parameterCount);

                GetGradient(
                    dataX[j],
                    parameters,
                    ref gradient);

                jacobian.SetRow(j, gradient);
            }
        }

        /// <summary>
        ///   Get vector of residuals for the specified parameters.
        /// </summary>
        /// <param name = "pointCount">Number of data points.</param>
        /// <param name = "dataX">X-coordinates of the data points.</param>
        /// <param name = "dataY">Y-coordinates of the data points.</param>
        /// <param name = "parameters">Model function parameters.</param>
        /// <param name = "residual">Vector of residuals.</param>
        private void GetResidualVector(
            int pointCount,
            Vector<double> dataX,
            Vector<double> dataY,
            Vector<double> parameters,
            ref Vector<double> residual)
        {
            double y;

            for (int j = 0; j < pointCount; j++)
            {
                GetValue(
                    dataX[j],
                    parameters,
                    out y);

                residual[j] = (y - dataY[j]);
            }
        }

        /// <summary>
        ///   Get value of the model function for the specified parameters.
        /// </summary>
        /// <param name = "x">X-coordinate of the function point.</param>
        /// <param name = "parameters">Model function parameters.</param>
        /// <param name = "y">Y-coordinate of the function point.</param>
        private void GetValue(
            double x,
            Vector<double> parameters,
            out double y)
        {
            y = parameters[0] * Math.Pow(x, parameters[1]);
        }

        /// <summary>
        ///   Get gradient of the model function for the specified parameters.
        /// </summary>
        /// <param name = "x">X-coordinate of the function point.</param>
        /// <param name = "parameters">Model function parameters.</param>
        /// <param name = "gradient">Model function gradient.</param>
        private void GetGradient(
            double x,
            Vector<double> parameters,
            ref Vector<double> gradient)
        {
            gradient[0] = Math.Pow(x, parameters[1]);
            gradient[1] = (parameters[0] * Math.Pow(x, parameters[1]) * Math.Log(x));
        }
    }
}
