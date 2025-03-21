//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// kmeans.cpp
//
// Code generation for function 'kmeans'
//

// Include files
#include "kmeans.h"
#include "find.h"
#include "mean.h"
#include "minOrMax.h"
#include "norm.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static double binary_expand_op(const ::coder::array<double, 2U> &in1, int in2,
    const ::coder::array<double, 2U> &in3, int in4);
  static void binary_expand_op(::coder::array<double, 2U> &in1, const int
    in2_data[], double in3, const ::coder::array<double, 2U> &in4, int in5);
  static double binary_expand_op(const ::coder::array<double, 2U> &in1, int in2,
    const ::coder::array<double, 2U> &in3);
}

// Function Definitions
namespace RAT
{
  static double binary_expand_op(const ::coder::array<double, 2U> &in1, int in2,
    const ::coder::array<double, 2U> &in3, int in4)
  {
    ::coder::array<double, 2U> b_in1;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    if (in3.size(1) == 1) {
      loop_ub = in1.size(1);
    } else {
      loop_ub = in3.size(1);
    }

    b_in1.set_size(1, loop_ub);
    stride_0_1 = (in1.size(1) != 1);
    stride_1_1 = (in3.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in1[i] = in1[in2 + in1.size(0) * (i * stride_0_1)] - in3[in4 + 2 * (i *
        stride_1_1)];
    }

    return coder::c_norm(b_in1);
  }

  static void binary_expand_op(::coder::array<double, 2U> &in1, const int
    in2_data[], double in3, const ::coder::array<double, 2U> &in4, int in5)
  {
    ::coder::array<double, 2U> b_in1;
    int in2_tmp;
    int stride_0_1;
    int stride_1_1;
    int unnamed_idx_1;
    in2_tmp = in2_data[static_cast<int>(in3) - 1];
    unnamed_idx_1 = in1.size(1);
    b_in1.set_size(1, unnamed_idx_1);
    stride_0_1 = (in1.size(1) != 1);
    stride_1_1 = (in4.size(1) != 1);
    for (int i{0}; i < unnamed_idx_1; i++) {
      b_in1[i] = in1[(in2_tmp + 2 * (i * stride_0_1)) - 1] + in4[in5 + in4.size
        (0) * (i * stride_1_1)];
    }

    unnamed_idx_1 = b_in1.size(1);
    for (int i{0}; i < unnamed_idx_1; i++) {
      in1[(in2_tmp + 2 * i) - 1] = b_in1[i];
    }
  }

  static double binary_expand_op(const ::coder::array<double, 2U> &in1, int in2,
    const ::coder::array<double, 2U> &in3)
  {
    ::coder::array<double, 2U> b_in1;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    if (in3.size(1) == 1) {
      loop_ub = in1.size(1);
    } else {
      loop_ub = in3.size(1);
    }

    b_in1.set_size(1, loop_ub);
    stride_0_1 = (in1.size(1) != 1);
    stride_1_1 = (in3.size(1) != 1);
    for (int i{0}; i < loop_ub; i++) {
      b_in1[i] = in1[in2 + 2 * (i * stride_0_1)] - in3[in2 + 2 * (i * stride_1_1)];
    }

    return coder::c_norm(b_in1);
  }

  void kmeans(const ::coder::array<double, 2U> &X, ::coder::array<double, 2U>
              &means, double Nmeans[2])
  {
    ::coder::array<double, 2U> b_X;
    ::coder::array<double, 2U> b_class;
    ::coder::array<double, 2U> c_X;
    double cmp;
    int index_min_data[2];
    int b_loop_ub;
    int i;
    int i1;
    int loop_ub;

    //    Mauricio Martinez-Garcia, 2003, 2007, 2016
    //  Perform K-means clustering for the data in ``X``.
    //
    //  Finds K prototypes representing the samples in data matrix X,
    //  where each row of X represents a sample.
    //  Iterates until maximum norm difference between
    //  prototypes found in successive iterations is < maxerr
    //
    //  This script uses square Euclidean distance,
    //  but can be easily modified to use other metrics.
    //
    //  Parameters
    //  ----------
    //  X : array
    //      An array of points, where each row of X is one point.
    //  K : int
    //      The number of clusters to separate the points into.
    //  maxerr : float
    //      The maximum norm difference between cluster prototypes.
    //
    //  Returns
    //  -------
    //  means : array
    //      matrix with each row a cluster prototype.
    //  Nmeans : array
    //      Number of samples in each cluster.
    //  membership : array
    //      Assigned class for each sample.
    //
    Nmeans[0] = 0.0;
    Nmeans[1] = 0.0;

    // coder.varsize('Nclass');
    // coder.varsize('class');
    means.set_size(2, X.size(1));
    loop_ub = X.size(1);

    //  Initial prototype assignment (arbitrary)
    for (i = 0; i < loop_ub; i++) {
      means[2 * i] = 0.0;
      means[2 * i + 1] = 0.0;
      means[2 * i] = X[X.size(0) * i];
    }

    if (X.size(0) < 2) {
      i = 0;
      i1 = 0;
    } else {
      i = 1;
      i1 = X.size(0);
    }

    loop_ub = i1 - i;
    b_X.set_size(loop_ub, X.size(1));
    b_loop_ub = X.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (int i2{0}; i2 < loop_ub; i2++) {
        b_X[i2 + b_X.size(0) * i1] = X[(i + i2) + X.size(0) * i1];
      }
    }

    coder::mean(b_X, c_X);
    loop_ub = means.size(1);
    for (i = 0; i < loop_ub; i++) {
      means[2 * i + 1] = c_X[i];
    }

    cmp = 1.0;
    while (cmp > 0.0) {
      //  Sums (class) and data counters (Nclass) initialization
      b_class.set_size(2, X.size(1));
      loop_ub = X.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_class[2 * i] = 0.0;
        b_class[2 * i + 1] = 0.0;
      }

      Nmeans[0] = 0.0;
      Nmeans[1] = 0.0;

      //  Groups each elements to the nearest prototype
      i = X.size(0);
      for (int b_i{0}; b_i < i; b_i++) {
        double dist[2];
        double a;
        loop_ub = X.size(1);
        for (int j{0}; j < 2; j++) {
          //  Euclidean distance from data to each prototype
          if (X.size(1) == means.size(1)) {
            c_X.set_size(1, X.size(1));
            for (i1 = 0; i1 < loop_ub; i1++) {
              c_X[i1] = X[b_i + X.size(0) * i1] - means[j + 2 * i1];
            }

            a = coder::c_norm(c_X);
          } else {
            a = binary_expand_op(X, b_i, means, j);
          }

          dist[j] = a * a;
        }

        int index_min_size[2];
        boolean_T b_dist[2];

        //  Find indices of minimum distance
        a = coder::internal::minimum(dist);
        b_dist[0] = !(dist[0] - a != 0.0);
        b_dist[1] = !(dist[1] - a != 0.0);
        coder::e_eml_find(b_dist, index_min_data, index_min_size);

        //  If there are multiple min distances, decide randomly
        a = static_cast<double>(index_min_size[1]) * coder::b_rand();
        a = std::ceil(a);
        if (b_class.size(1) == X.size(1)) {
          b_loop_ub = index_min_data[static_cast<int>(a) - 1];
          c_X.set_size(1, b_class.size(1));
          loop_ub = b_class.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            c_X[i1] = b_class[(b_loop_ub + 2 * i1) - 1] + X[b_i + X.size(0) * i1];
          }

          loop_ub = c_X.size(1);
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_class[(b_loop_ub + 2 * i1) - 1] = c_X[i1];
          }
        } else {
          binary_expand_op(b_class, index_min_data, a, X, b_i);
        }

        b_loop_ub = index_min_data[static_cast<int>(a) - 1] - 1;
        Nmeans[b_loop_ub]++;
      }

      for (int b_i{0}; b_i < 2; b_i++) {
        c_X.set_size(1, b_class.size(1));
        loop_ub = b_class.size(1);
        for (i = 0; i < loop_ub; i++) {
          c_X[i] = b_class[b_i + 2 * i] / Nmeans[b_i];
        }

        loop_ub = c_X.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_class[b_i + 2 * i] = c_X[i];
        }
      }

      //  Compare results with previous iteration
      cmp = 0.0;
      loop_ub = b_class.size(1);
      for (int b_i{0}; b_i < 2; b_i++) {
        if (b_class.size(1) == means.size(1)) {
          c_X.set_size(1, b_class.size(1));
          for (i = 0; i < loop_ub; i++) {
            c_X[i] = b_class[b_i + 2 * i] - means[b_i + 2 * i];
          }

          cmp = coder::c_norm(c_X);
        } else {
          cmp = binary_expand_op(b_class, b_i, means);
        }
      }

      //  Prototype update
      means.set_size(2, b_class.size(1));
      loop_ub = b_class.size(1);
      for (i = 0; i < loop_ub; i++) {
        means[2 * i] = b_class[2 * i];
        means[2 * i + 1] = b_class[2 * i + 1];
      }
    }
  }
}

// End of code generation (kmeans.cpp)
