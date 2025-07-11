//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// splitEllipsoid.cpp
//
// Code generation for function 'splitEllipsoid'
//

// Include files
#include "splitEllipsoid.h"
#include "RATMain_types.h"
#include "calcEllipsoid.h"
#include "eml_mtimes_helper.h"
#include "ifWhileCond.h"
#include "kmeans.h"
#include "makeCell.h"
#include "minOrMax.h"
#include "mrdivide_helper.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
namespace RAT
{
  static void binary_expand_op(double in1[50], int in2, const double in3_data[],
    const int in3_size[2], const double in4_data[], const int in4_size[2],
    double in5);
}

// Function Definitions
namespace RAT
{
  static void binary_expand_op(double in1[50], int in2, const double in3_data[],
    const int in3_size[2], const double in4_data[], const int in4_size[2],
    double in5)
  {
    double b_in3_data;
    int aux_0_1;
    int aux_1_1;
    int b_loop_ub;
    int loop_ub;
    int stride_0_1;
    int stride_1_1;
    if (in4_size[0] == 1) {
      loop_ub = in3_size[0];
    } else {
      loop_ub = in4_size[0];
    }

    if (in4_size[1] == 1) {
      b_loop_ub = in3_size[1];
    } else {
      b_loop_ub = in4_size[1];
    }

    stride_0_1 = (in3_size[1] != 1);
    stride_1_1 = (in4_size[1] != 1);
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_in3_data = in3_data[in3_size[0] * aux_0_1] + in4_data[in4_size[0] *
          aux_1_1];
      }

      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }

    in1[in2] = b_in3_data / in5;
  }

  double splitEllipsoid(const ::coder::array<double, 2U> &u, double VS, ::coder::
                        array<double, 2U> &u1, ::coder::array<double, 2U> &u2,
                        double VE1_data[], int VE1_size[2], double VE2_data[],
                        int VE2_size[2])
  {
    ::coder::array<double, 2U> B1;
    ::coder::array<double, 2U> B2;
    ::coder::array<double, 2U> b_u;
    ::coder::array<double, 2U> idx;
    ::coder::array<double, 2U> mu1;
    ::coder::array<double, 2U> mu2;
    ::coder::array<double, 2U> r2;
    ::coder::array<double, 2U> u1new;
    ::coder::array<double, 2U> u2new;
    ::coder::array<int, 1U> r;
    ::coder::array<int, 1U> r1;
    ::coder::array<boolean_T, 2U> d_tmp_data;
    cell_wrap_9 temp_u1_tmp[50];
    double mu[2];
    double VE1_tmp_data;
    double b_tmp_data;
    double tmp_data;
    int D;
    int N;
    int b_nosplit;
    boolean_T c_tmp_data;

    //  Optimally bound a set of points by two ellipsoids.
    //
    //  It uses the k-means algorthim to
    //  split the points into two sub-clusters and uses an optimisation scheme to
    //  re-assign points, if necessary, between the sub-clusters. This is based
    //  on the description in Algorithm 1 of the MultiNest paper by Feroz,
    //  Hobson, and Bridges.
    //
    //  Parameters
    //  ----------
    //  u : array
    //      The points to bound by two ellipsoids.
    //  VS : float
    //      The minimum volume of the ellipsoids.
    //
    //  Returns
    //  -------
    //  u1, u2 : array
    //      The points in each ellipsoid.
    //  VE1, VE2 : float
    //      The volume of each ellipsoid.
    //  nosplit : bool
    //      Equals 1 if splitting into two ellipsoids is not possible.
    //
    //  maximum number of attempts to recluster points
    //  default return values
    b_nosplit = 0;
    VE1_size[0] = 0;
    VE1_size[1] = 0;
    VE2_size[0] = 0;
    VE2_size[1] = 0;
    u1.set_size(0, 0);
    u2.set_size(0, 0);

    //  extract number of samples and number of dimensions
    N = u.size(0);
    D = u.size(1);

    //  check total number of samples
    if (u.size(0) < 2.0 * (static_cast<double>(u.size(1)) + 1.0)) {
      b_nosplit = 1;
    } else {
      int b_loop_ub;
      int end_tmp;
      int iindx;
      int loop_ub;
      int n1;
      int n2;

      //  use kmeans to separate the data points into two sub-clusters
      kmeans(u, idx, mu);
      iindx = idx.size(1) << 1;
      end_tmp = iindx - 1;
      iindx = 0;
      for (int i{0}; i <= end_tmp; i++) {
        if (idx[i] == 1.0) {
          iindx++;
        }
      }

      r.set_size(iindx);
      iindx = 0;
      for (int i{0}; i <= end_tmp; i++) {
        if (idx[i] == 1.0) {
          r[iindx] = i;
          iindx++;
        }
      }

      u1.set_size(r.size(0), u.size(1));
      loop_ub = u.size(1);
      for (int b_i{0}; b_i < loop_ub; b_i++) {
        b_loop_ub = r.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          u1[i1 + u1.size(0) * b_i] = u[r[i1] + u.size(0) * b_i];
        }
      }

      iindx = 0;
      for (int i{0}; i <= end_tmp; i++) {
        if (idx[i] == 2.0) {
          iindx++;
        }
      }

      r1.set_size(iindx);
      iindx = 0;
      for (int i{0}; i <= end_tmp; i++) {
        if (idx[i] == 2.0) {
          r1[iindx] = i;
          iindx++;
        }
      }

      u2.set_size(r1.size(0), u.size(1));
      loop_ub = u.size(1);
      for (int b_i{0}; b_i < loop_ub; b_i++) {
        b_loop_ub = r1.size(0);
        for (int i1{0}; i1 < b_loop_ub; i1++) {
          u2[i1 + u2.size(0) * b_i] = u[r1[i1] + u.size(0) * b_i];
        }
      }

      n1 = r.size(0);

      //  number of samples in S1
      n2 = r1.size(0);

      //  number of samples in S2
      //  check number of points in subclusters
      if ((static_cast<unsigned int>(r.size(0)) < static_cast<unsigned int>
           (u.size(1)) + 1U) || (static_cast<unsigned int>(r1.size(0)) <
           static_cast<unsigned int>(u.size(1)) + 1U)) {
        b_nosplit = 1;
      } else {
        cell_wrap_9 temp_u2[50];
        double FS[50];
        double temp_VE1[50];
        double temp_VE2[50];
        int counter;

        //  preallocate temp arrays
        makeCell(temp_u1_tmp);
        for (int i{0}; i < 50; i++) {
          temp_u2[i] = temp_u1_tmp[i];
          temp_VE1[i] = 0.0;
          temp_VE2[i] = 0.0;
          FS[i] = 0.0;
        }

        // %%%%%%%%%%%%%%%%%%%%%%%%%
        counter = 0;
        double VS1;
        double VS2;
        double flag1;
        double flag2;
        int exitg1;
        do {
          exitg1 = 0;

          //  calculate minimum volume of ellipsoids
          VS1 = VS * static_cast<double>(n1) / static_cast<double>(N);
          VS2 = VS * static_cast<double>(n2) / static_cast<double>(N);

          //  calculate properties of bounding ellipsoids for the two subclusters
          flag1 = calcEllipsoid(u1, VS1, B1, mu1, VE1_data, VE1_size);
          flag2 = calcEllipsoid(u2, VS2, B2, mu2, VE2_data, VE2_size);

          //  check flags
          if ((flag1 != 0.0) || (flag2 != 0.0)) {
            b_nosplit = 1;
            exitg1 = 1;
          } else {
            int c_loop_ub;
            unsigned int m1;
            unsigned int m2;
            int reassign;

            //  construct temporary arrays and cell arrays containing results for
            //  each pass through the loop
            temp_u1_tmp[counter].f1.set_size(u1.size(0), u1.size(1));
            loop_ub = u1.size(1);
            temp_u2[counter].f1.set_size(u2.size(0), u2.size(1));
            for (int b_i{0}; b_i < loop_ub; b_i++) {
              b_loop_ub = u1.size(0);
              for (int i1{0}; i1 < b_loop_ub; i1++) {
                temp_u1_tmp[counter].f1[i1 + temp_u1_tmp[counter].f1.size(0) *
                  b_i] = u1[i1 + u1.size(0) * b_i];
              }

              b_loop_ub = u2.size(0);
              for (int i1{0}; i1 < b_loop_ub; i1++) {
                temp_u2[counter].f1[i1 + temp_u2[counter].f1.size(0) * b_i] =
                  u2[i1 + u2.size(0) * b_i];
              }
            }

            temp_VE1[counter] = VE1_data[0];
            temp_VE2[counter] = VE2_data[0];
            if ((VE1_size[0] == VE2_size[0]) && (VE1_size[1] == VE2_size[1])) {
              FS[counter] = (VE1_data[0] + VE2_data[0]) / VS;
            } else {
              binary_expand_op(FS, counter, VE1_data, VE1_size, VE2_data,
                               VE2_size, VS);
            }

            // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            //  check if points need to be reassigned to the other subcluster
            reassign = 0;
            m1 = 0U;
            m2 = 0U;
            u1new.set_size(N, D);
            u2new.set_size(N, D);
            for (int b_i{0}; b_i < D; b_i++) {
              for (int i1{0}; i1 < N; i1++) {
                u1new[i1 + u1new.size(0) * b_i] = 0.0;
                u2new[i1 + u2new.size(0) * b_i] = 0.0;
              }
            }

            //  for all points get the Mahalanobis distance between each point and
            //  the centroid of each ellipse and assign accordingly
            loop_ub = u.size(1);
            b_loop_ub = u.size(1);
            c_loop_ub = u.size(1);
            iindx = u.size(1);
            for (int i{0}; i < N; i++) {
              int VE1_tmp_size[2];
              int b_tmp_size[2];
              int tmp_size[2];
              int d_loop_ub;

              //  get d = (u-mu)^T * B^-1 * (u-mu)
              //  calculate hk = VEk * duk / VSk;
              if (u.size(1) == mu1.size(1)) {
                b_u.set_size(mu1.size(0), u.size(1));
                for (int b_i{0}; b_i < loop_ub; b_i++) {
                  end_tmp = mu1.size(0);
                  for (int i1{0}; i1 < end_tmp; i1++) {
                    b_u[b_u.size(0) * b_i] = u[i + u.size(0) * b_i] -
                      mu1[mu1.size(0) * b_i];
                  }
                }

                coder::internal::mrdiv(b_u, B1, r2);
              } else {
                c_binary_expand_op(r2, u, i, mu1, B1);
              }

              if (u.size(1) == mu1.size(1)) {
                b_u.set_size(mu1.size(0), u.size(1));
                for (int b_i{0}; b_i < b_loop_ub; b_i++) {
                  end_tmp = mu1.size(0);
                  for (int i1{0}; i1 < end_tmp; i1++) {
                    b_u[b_u.size(0) * b_i] = u[i + u.size(0) * b_i] -
                      mu1[mu1.size(0) * b_i];
                  }
                }

                coder::internal::blas::mtimes(r2, b_u, (double *)&VE1_tmp_data,
                  VE1_tmp_size);
              } else {
                c_binary_expand_op((double *)&VE1_tmp_data, r2, u, i, mu1,
                                   VE1_tmp_size);
              }

              coder::internal::blas::mtimes(VE1_data, VE1_size, (const double *)
                &VE1_tmp_data, VE1_tmp_size, (double *)&tmp_data, tmp_size);
              if (u.size(1) == mu2.size(1)) {
                b_u.set_size(mu2.size(0), u.size(1));
                for (int b_i{0}; b_i < c_loop_ub; b_i++) {
                  end_tmp = mu2.size(0);
                  for (int i1{0}; i1 < end_tmp; i1++) {
                    b_u[b_u.size(0) * b_i] = u[i + u.size(0) * b_i] -
                      mu2[mu2.size(0) * b_i];
                  }
                }

                coder::internal::mrdiv(b_u, B2, r2);
              } else {
                c_binary_expand_op(r2, u, i, mu2, B2);
              }

              if (u.size(1) == mu2.size(1)) {
                b_u.set_size(mu2.size(0), u.size(1));
                for (int b_i{0}; b_i < iindx; b_i++) {
                  end_tmp = mu2.size(0);
                  for (int i1{0}; i1 < end_tmp; i1++) {
                    b_u[b_u.size(0) * b_i] = u[i + u.size(0) * b_i] -
                      mu2[mu2.size(0) * b_i];
                  }
                }

                coder::internal::blas::mtimes(r2, b_u, (double *)&VE1_tmp_data,
                  VE1_tmp_size);
              } else {
                c_binary_expand_op((double *)&VE1_tmp_data, r2, u, i, mu2,
                                   VE1_tmp_size);
              }

              coder::internal::blas::mtimes(VE2_data, VE2_size, (const double *)
                &VE1_tmp_data, VE1_tmp_size, (double *)&b_tmp_data, b_tmp_size);
              if (b_tmp_size[0] == 1) {
                end_tmp = tmp_size[0];
              } else {
                end_tmp = b_tmp_size[0];
              }

              if (b_tmp_size[1] == 1) {
                d_loop_ub = tmp_size[1];
              } else {
                d_loop_ub = b_tmp_size[1];
              }

              for (int b_i{0}; b_i < d_loop_ub; b_i++) {
                for (int i1{0}; i1 < end_tmp; i1++) {
                  c_tmp_data = (tmp_data / VS1 < b_tmp_data / VS2);
                }
              }

              d_tmp_data.set(&c_tmp_data, end_tmp, d_loop_ub);
              if (coder::internal::b_ifWhileCond(d_tmp_data)) {
                m1++;
                end_tmp = u1new.size(1);
                for (int b_i{0}; b_i < end_tmp; b_i++) {
                  u1new[(static_cast<int>(m1) + u1new.size(0) * b_i) - 1] = u[i
                    + u.size(0) * b_i];
                }

                //  check if point has been reassigned or not
                if (idx[i] != 1.0) {
                  reassign = 1;
                  idx[i] = 1.0;
                }
              } else {
                m2++;
                end_tmp = u2new.size(1);
                for (int b_i{0}; b_i < end_tmp; b_i++) {
                  u2new[(static_cast<int>(m2) + u2new.size(0) * b_i) - 1] = u[i
                    + u.size(0) * b_i];
                }

                //  check if point has been reassigned or not
                if (idx[i] != 2.0) {
                  reassign = 1;
                  idx[i] = 2.0;
                }
              }
            }

            n1 = static_cast<int>(m1);
            n2 = static_cast<int>(m2);
            if (static_cast<int>(m1) < 1) {
              loop_ub = 0;
            } else {
              loop_ub = static_cast<int>(m1);
            }

            u1.set_size(loop_ub, u1new.size(1));
            b_loop_ub = u1new.size(1);
            if (static_cast<int>(m2) < 1) {
              c_loop_ub = 0;
            } else {
              c_loop_ub = static_cast<int>(m2);
            }

            u2.set_size(c_loop_ub, u2new.size(1));
            for (int b_i{0}; b_i < b_loop_ub; b_i++) {
              for (int i1{0}; i1 < loop_ub; i1++) {
                u1[i1 + u1.size(0) * b_i] = u1new[i1 + u1new.size(0) * b_i];
              }

              for (int i1{0}; i1 < c_loop_ub; i1++) {
                u2[i1 + u2.size(0) * b_i] = u2new[i1 + u2new.size(0) * b_i];
              }
            }

            //  update counter
            counter++;
            if ((reassign == 0) || (counter + 1 > 50)) {
              exitg1 = 1;
            }
          }
        } while (exitg1 == 0);

        //  find minimum F(S) and return
        coder::internal::minimum(FS, iindx);
        u1.set_size(temp_u1_tmp[iindx - 1].f1.size(0), temp_u1_tmp[iindx - 1].
                    f1.size(1));
        loop_ub = temp_u1_tmp[iindx - 1].f1.size(1);
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          b_loop_ub = temp_u1_tmp[iindx - 1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            u1[i1 + u1.size(0) * b_i] = temp_u1_tmp[iindx - 1].f1[i1 +
              temp_u1_tmp[iindx - 1].f1.size(0) * b_i];
          }
        }

        u2.set_size(temp_u2[iindx - 1].f1.size(0), temp_u2[iindx - 1].f1.size(1));
        loop_ub = temp_u2[iindx - 1].f1.size(1);
        for (int b_i{0}; b_i < loop_ub; b_i++) {
          b_loop_ub = temp_u2[iindx - 1].f1.size(0);
          for (int i1{0}; i1 < b_loop_ub; i1++) {
            u2[i1 + u2.size(0) * b_i] = temp_u2[iindx - 1].f1[i1 + temp_u2[iindx
              - 1].f1.size(0) * b_i];
          }
        }

        VE1_size[0] = 1;
        VE1_size[1] = 1;
        VE1_data[0] = temp_VE1[iindx - 1];
        VE2_size[0] = 1;
        VE2_size[1] = 1;
        VE2_data[0] = temp_VE2[iindx - 1];
      }
    }

    return b_nosplit;
  }
}

// End of code generation (splitEllipsoid.cpp)
