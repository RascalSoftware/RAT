//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
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

// Function Definitions
namespace RAT
{
  void kmeans(const ::coder::array<real_T, 2U> &X, ::coder::array<real_T, 2U>
              &means, real_T Nmeans[2])
  {
    ::coder::array<real_T, 2U> b_X;
    ::coder::array<real_T, 2U> b_class;
    ::coder::array<real_T, 2U> c_X;
    real_T dist[2];
    real_T cmp;
    int32_T index_min_data[2];
    int32_T index_min_size[2];
    int32_T b_loop_ub;
    int32_T c_loop_ub;
    int32_T i;
    int32_T i1;
    int32_T index_min_tmp_tmp;
    int32_T loop_ub;
    boolean_T b_dist[2];

    //    Finds K prototypes representing the samples in data matrix X,
    //    where each row of X represents a sample.
    //    Iterates until maximum norm difference between
    //    prototypes found in successive iterations is < maxerr
    //
    //    This script uses square Euclidean distance,
    //    but can be easily modified to use other metrics
    //
    //  Output arguments
    //    means: matrix with each row a cluster prototype
    //    Nmeans: Number of samples in each cluster
    //    membership: Assigned class for each sample
    //
    //  Example:
    //    X = [randn(100,1) ;  2+randn(100,1)];
    //    K = 2;
    //    [means Nmeans] = kmeans(X,K,0)
    //
    //    Mauricio Martinez-Garcia, 2003, 2007, 2016
    Nmeans[0] = 0.0;
    Nmeans[1] = 0.0;

    // coder.varsize('Nclass');
    // coder.varsize('class');
    means.set_size(2, X.size(1));
    loop_ub = X.size(1);
    for (i = 0; i < loop_ub; i++) {
      means[2 * i] = 0.0;
      means[2 * i + 1] = 0.0;
    }

    //  Initial prototype assignment (arbitrary)
    loop_ub = X.size(1);
    for (i = 0; i < loop_ub; i++) {
      means[2 * i] = X[X.size(0) * i];
    }

    if (2 > X.size(0)) {
      i = 0;
      i1 = 0;
    } else {
      i = 1;
      i1 = X.size(0);
    }

    loop_ub = X.size(1);
    b_loop_ub = i1 - i;
    b_X.set_size(b_loop_ub, X.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (index_min_tmp_tmp = 0; index_min_tmp_tmp < b_loop_ub;
           index_min_tmp_tmp++) {
        b_X[index_min_tmp_tmp + b_X.size(0) * i1] = X[(i + index_min_tmp_tmp) +
          X.size(0) * i1];
      }
    }

    coder::mean(b_X, c_X);
    loop_ub = c_X.size(1);
    for (i = 0; i < loop_ub; i++) {
      means[2 * i + 1] = c_X[i];
    }

    loop_ub = X.size(1);
    i = X.size(0);
    if (0 <= i - 1) {
      c_loop_ub = X.size(1);
    }

    cmp = 1.0;
    while (cmp > 0.0) {
      int32_T b_i;

      //  Sums (class) and data counters (Nclass) initialization
      b_class.set_size(2, X.size(1));
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_class[2 * i1] = 0.0;
        b_class[2 * i1 + 1] = 0.0;
      }

      Nmeans[0] = 0.0;
      Nmeans[1] = 0.0;

      //  Groups each elements to the nearest prototype
      for (b_i = 0; b_i < i; b_i++) {
        real_T a;
        for (int32_T j{0}; j < 2; j++) {
          //  Euclidean distance from data to each prototype
          c_X.set_size(1, c_loop_ub);
          for (i1 = 0; i1 < c_loop_ub; i1++) {
            c_X[i1] = X[b_i + X.size(0) * i1] - means[j + 2 * i1];
          }

          if (c_X.size(1) == 0) {
            a = 0.0;
          } else {
            a = coder::b_genpnorm(c_X);
          }

          dist[j] = a * a;
        }

        //  Find indices of minimum distance
        a = coder::internal::minimum(dist);
        b_dist[0] = !(dist[0] - a != 0.0);
        b_dist[1] = !(dist[1] - a != 0.0);
        coder::d_eml_find(b_dist, index_min_data, index_min_size);

        //  If there are multiple min distances, decide randomly
        a = static_cast<real_T>(index_min_size[1]) * coder::b_rand();
        a = std::ceil(a);
        b_loop_ub = b_class.size(1) - 1;
        index_min_tmp_tmp = index_min_data[static_cast<int32_T>(a) - 1];
        c_X.set_size(1, b_class.size(1));
        for (i1 = 0; i1 <= b_loop_ub; i1++) {
          c_X[i1] = b_class[(index_min_tmp_tmp + 2 * i1) - 1] + X[b_i + X.size(0)
            * i1];
        }

        b_loop_ub = c_X.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_class[(index_min_tmp_tmp + 2 * i1) - 1] = c_X[i1];
        }

        Nmeans[index_min_tmp_tmp - 1]++;
      }

      for (b_i = 0; b_i < 2; b_i++) {
        b_loop_ub = b_class.size(1) - 1;
        c_X.set_size(1, b_class.size(1));
        for (i1 = 0; i1 <= b_loop_ub; i1++) {
          c_X[i1] = b_class[b_i + 2 * i1] / Nmeans[b_i];
        }

        b_loop_ub = c_X.size(1);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_class[b_i + 2 * i1] = c_X[i1];
        }
      }

      //  Compare results with previous iteration
      cmp = 0.0;
      b_loop_ub = b_class.size(1);
      for (b_i = 0; b_i < 2; b_i++) {
        c_X.set_size(1, b_loop_ub);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          c_X[i1] = b_class[b_i + 2 * i1] - means[b_i + 2 * i1];
        }

        if (c_X.size(1) == 0) {
          cmp = 0.0;
        } else {
          cmp = coder::b_genpnorm(c_X);
        }
      }

      //  Prototype update
      means.set_size(2, b_class.size(1));
      b_loop_ub = b_class.size(1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        means[2 * i1] = b_class[2 * i1];
        means[2 * i1 + 1] = b_class[2 * i1 + 1];
      }
    }
  }
}

// End of code generation (kmeans.cpp)
