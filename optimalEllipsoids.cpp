//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// optimalEllipsoids.cpp
//
// Code generation for function 'optimalEllipsoids'
//

// Include files
#include "optimalEllipsoids.h"
#include "RATMain_data.h"
#include "all.h"
#include "calcEllipsoid.h"
#include "print_processing.h"
#include "rt_nonfinite.h"
#include "splitEllipsoid.h"
#include "coder_array.h"
#include <stdio.h>

// Function Definitions
namespace RAT
{
  void optimalEllipsoids(const ::coder::array<double, 2U> &u, double VS, ::coder::
    array<double, 2U> &Bs, ::coder::array<double, 2U> &mus, ::coder::array<
    double, 2U> &VEs, ::coder::array<double, 2U> &ns)
  {
    ::coder::array<double, 2U> B1;
    ::coder::array<double, 2U> B2;
    ::coder::array<double, 2U> VE1;
    ::coder::array<double, 2U> VE2;
    ::coder::array<double, 2U> mu;
    ::coder::array<double, 2U> mu1;
    ::coder::array<double, 2U> mu2;
    ::coder::array<double, 2U> n1;
    ::coder::array<double, 2U> n2;
    ::coder::array<double, 2U> u1;
    ::coder::array<double, 2U> u2;
    double VE1_data;
    double VE2_data;
    double VE_data;
    double flag;
    double nosplit;
    int validatedHoleFilling[3];
    int VE1_size[2];
    int VE2_size[2];
    int VE_size[2];
    int b_VE1_size[2];
    boolean_T empty_non_axis_sizes;
    boolean_T tmp_data;

    //  function [Bs, mus, VEs, ns] = optimalEllipsoids(u, VS)
    //
    //  This function attempts to optimally partition the multi-dimensional
    //  samples u (uniformly distributed within the sample volume VS), into
    //  a set of subclusters enclosed by bounding ellipsoids.  The algorithm
    //  is based on Algorithm 1 of the MULTINEST paper by Feroz, Hobson,
    //  and Bridges, MNRAS, 398, 1601-1614 (2009).
    //
    //  Output:
    //    Bs:  an array of bounding matrices for the ellipsoids enclosing
    //         the subclusters, scaled to have at least the minimum volume
    //         required by the subclusters. ( (K x ndims) x ndims )
    //    mus: an array of centroids for the bounding ellipsoids (K x ndims)
    //    VEs: an array of volumes for the bounding ellipsoids   (K x 1)
    //    ns:  an array containing the number of points for each subcluster (K x 1)
    //
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    //  number of samples in multi-dimensional space
    //  number of dimensions
    //  calculate bounding matrix, etc. for bounding ellipsoid associated
    //  with the original set of points u
    calcEllipsoid(u, VS, Bs, mu, (double *)&VE_data, VE_size, &flag);

    //  attempt to split u into two subclusters
    splitEllipsoid(u, VS, u1, u2, (double *)&VE1_data, VE1_size, (double *)
                   &VE2_data, VE2_size, &nosplit);
    if ((nosplit != 0.0) || (static_cast<unsigned int>(u1.size(0)) < u.size(1) +
         1U) || (static_cast<unsigned int>(u2.size(0)) < u.size(1) + 1U)) {
      int i;
      int i1;
      int input_sizes_idx_0;
      int loop_ub;

      //  couldn't split the cluster
      mus.set_size(mu.size(0), mu.size(1));
      input_sizes_idx_0 = mu.size(1);
      for (i = 0; i < input_sizes_idx_0; i++) {
        loop_ub = mu.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          mus[mus.size(0) * i] = mu[mu.size(0) * i];
        }
      }

      VEs.set_size(VE_size[0], VE_size[1]);
      input_sizes_idx_0 = VE_size[1];
      for (i = 0; i < input_sizes_idx_0; i++) {
        loop_ub = VE_size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          VEs[0] = VE_data;
        }
      }

      ns.set_size(1, 1);
      ns[0] = u.size(0);
    } else {
      int i;
      int i1;
      int input_sizes_idx_0;
      int loop_ub;
      boolean_T guard1{ false };

      //  check if we should keep the partitioning of S
      // if (all(VE1 + VE2 < VE) || all(VE > 2*VS))
      b_VE1_size[0] = VE1_size[0];
      b_VE1_size[1] = VE1_size[1];
      input_sizes_idx_0 = VE1_size[1];
      for (i = 0; i < input_sizes_idx_0; i++) {
        loop_ub = VE1_size[0];
        for (i1 = 0; i1 < loop_ub; i1++) {
          empty_non_axis_sizes = (VE1_data + VE2_data < VE_data);
        }
      }

      coder::all((const boolean_T *)&empty_non_axis_sizes, b_VE1_size,
                 (boolean_T *)&tmp_data, VE1_size);
      guard1 = false;
      if (coder::b_all((const boolean_T *)&tmp_data, VE1_size)) {
        guard1 = true;
      } else {
        flag = 2.0 * VS;
        b_VE1_size[0] = VE_size[0];
        b_VE1_size[1] = VE_size[1];
        input_sizes_idx_0 = VE_size[1];
        for (i = 0; i < input_sizes_idx_0; i++) {
          loop_ub = VE_size[0];
          for (i1 = 0; i1 < loop_ub; i1++) {
            empty_non_axis_sizes = (VE_data > flag);
          }
        }

        coder::all((const boolean_T *)&empty_non_axis_sizes, b_VE1_size,
                   (boolean_T *)&tmp_data, VE1_size);
        if (coder::b_all((const boolean_T *)&tmp_data, VE1_size)) {
          guard1 = true;
        } else {
          if (DEBUG != 0.0) {
            coder::internal::print_processing(u.size(0), u1.size(0), u2.size(0),
              validatedHoleFilling);
            printf("PARTITION REJECTED: N=%d doesnt split into n1=%d and n2=%d\n",
                   validatedHoleFilling[0], validatedHoleFilling[1],
                   validatedHoleFilling[2]);
            fflush(stdout);
          }

          mus.set_size(mu.size(0), mu.size(1));
          input_sizes_idx_0 = mu.size(1);
          for (i = 0; i < input_sizes_idx_0; i++) {
            loop_ub = mu.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              mus[mus.size(0) * i] = mu[mu.size(0) * i];
            }
          }

          VEs.set_size(VE_size[0], VE_size[1]);
          input_sizes_idx_0 = VE_size[1];
          for (i = 0; i < input_sizes_idx_0; i++) {
            loop_ub = VE_size[0];
            for (i1 = 0; i1 < loop_ub; i1++) {
              VEs[0] = VE_data;
            }
          }

          ns.set_size(1, 1);
          ns[0] = u.size(0);
        }
      }

      if (guard1) {
        int result;
        int sizes_idx_0;
        short b_input_sizes_idx_0;
        if (DEBUG != 0.0) {
          coder::internal::print_processing(u.size(0), u1.size(0), u2.size(0),
            validatedHoleFilling);
          printf("PARTITION ACCEPTED: N=%d splits to n1=%d, n2=%d\n",
                 validatedHoleFilling[0], validatedHoleFilling[1],
                 validatedHoleFilling[2]);
          fflush(stdout);
        }

        optimalEllipsoids(u1, static_cast<double>(u1.size(0)) * VS /
                          static_cast<double>(u.size(0)), B1, mu1, VE1, n1);
        optimalEllipsoids(u2, static_cast<double>(u2.size(0)) * VS /
                          static_cast<double>(u.size(0)), B2, mu2, VE2, n2);
        if ((B1.size(0) != 0) && (B1.size(1) != 0)) {
          result = B1.size(1);
        } else if ((B2.size(0) != 0) && (B2.size(1) != 0)) {
          result = B2.size(1);
        } else {
          result = B1.size(1);
          if (B2.size(1) > B1.size(1)) {
            result = B2.size(1);
          }
        }

        empty_non_axis_sizes = (result == 0);
        if (empty_non_axis_sizes || ((B1.size(0) != 0) && (B1.size(1) != 0))) {
          input_sizes_idx_0 = B1.size(0);
        } else {
          input_sizes_idx_0 = 0;
        }

        if (empty_non_axis_sizes || ((B2.size(0) != 0) && (B2.size(1) != 0))) {
          sizes_idx_0 = B2.size(0);
        } else {
          sizes_idx_0 = 0;
        }

        Bs.set_size(input_sizes_idx_0 + sizes_idx_0, result);
        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
            Bs[i1 + Bs.size(0) * i] = B1[i1 + input_sizes_idx_0 * i];
          }
        }

        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < sizes_idx_0; i1++) {
            Bs[(i1 + input_sizes_idx_0) + Bs.size(0) * i] = B2[i1 + sizes_idx_0 *
              i];
          }
        }

        if ((mu1.size(0) != 0) && (mu1.size(1) != 0)) {
          result = mu1.size(1);
        } else if ((mu2.size(0) != 0) && (mu2.size(1) != 0)) {
          result = mu2.size(1);
        } else {
          result = mu1.size(1);
          if (mu2.size(1) > mu1.size(1)) {
            result = mu2.size(1);
          }
        }

        empty_non_axis_sizes = (result == 0);
        if (empty_non_axis_sizes || ((mu1.size(0) != 0) && (mu1.size(1) != 0)))
        {
          b_input_sizes_idx_0 = static_cast<short>(mu1.size(0));
        } else {
          b_input_sizes_idx_0 = 0;
        }

        if (empty_non_axis_sizes || ((mu2.size(0) != 0) && (mu2.size(1) != 0)))
        {
          sizes_idx_0 = mu2.size(0);
        } else {
          sizes_idx_0 = 0;
        }

        loop_ub = b_input_sizes_idx_0;
        mus.set_size(b_input_sizes_idx_0 + sizes_idx_0, result);
        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            mus[i1 + mus.size(0) * i] = mu1[i1 + b_input_sizes_idx_0 * i];
          }
        }

        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < sizes_idx_0; i1++) {
            mus[(i1 + b_input_sizes_idx_0) + mus.size(0) * i] = mu2[i1 +
              sizes_idx_0 * i];
          }
        }

        if ((VE1.size(0) != 0) && (VE1.size(1) != 0)) {
          result = VE1.size(1);
        } else if ((VE2.size(0) != 0) && (VE2.size(1) != 0)) {
          result = VE2.size(1);
        } else {
          result = VE1.size(1);
          if (VE2.size(1) > VE1.size(1)) {
            result = VE2.size(1);
          }
        }

        empty_non_axis_sizes = (result == 0);
        if (empty_non_axis_sizes || ((VE1.size(0) != 0) && (VE1.size(1) != 0)))
        {
          input_sizes_idx_0 = VE1.size(0);
        } else {
          input_sizes_idx_0 = 0;
        }

        if (empty_non_axis_sizes || ((VE2.size(0) != 0) && (VE2.size(1) != 0)))
        {
          sizes_idx_0 = VE2.size(0);
        } else {
          sizes_idx_0 = 0;
        }

        VEs.set_size(input_sizes_idx_0 + sizes_idx_0, result);
        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < input_sizes_idx_0; i1++) {
            VEs[i1 + VEs.size(0) * i] = VE1[i1 + input_sizes_idx_0 * i];
          }
        }

        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < sizes_idx_0; i1++) {
            VEs[(i1 + input_sizes_idx_0) + VEs.size(0) * i] = VE2[i1 +
              sizes_idx_0 * i];
          }
        }

        if ((n1.size(0) != 0) && (n1.size(1) != 0)) {
          result = n1.size(1);
        } else if ((n2.size(0) != 0) && (n2.size(1) != 0)) {
          result = n2.size(1);
        } else {
          result = n1.size(1);
          if (n2.size(1) > n1.size(1)) {
            result = n2.size(1);
          }
        }

        empty_non_axis_sizes = (result == 0);
        if (empty_non_axis_sizes || ((n1.size(0) != 0) && (n1.size(1) != 0))) {
          b_input_sizes_idx_0 = static_cast<short>(n1.size(0));
        } else {
          b_input_sizes_idx_0 = 0;
        }

        if (empty_non_axis_sizes || ((n2.size(0) != 0) && (n2.size(1) != 0))) {
          sizes_idx_0 = n2.size(0);
        } else {
          sizes_idx_0 = 0;
        }

        loop_ub = b_input_sizes_idx_0;
        ns.set_size(b_input_sizes_idx_0 + sizes_idx_0, result);
        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            ns[i1 + ns.size(0) * i] = n1[i1 + b_input_sizes_idx_0 * i];
          }
        }

        for (i = 0; i < result; i++) {
          for (i1 = 0; i1 < sizes_idx_0; i1++) {
            ns[(i1 + b_input_sizes_idx_0) + ns.size(0) * i] = n2[i1 +
              sizes_idx_0 * i];
          }
        }
      }
    }
  }
}

// End of code generation (optimalEllipsoids.cpp)
