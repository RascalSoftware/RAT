//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// makeCell.cpp
//
// Code generation for function 'makeCell'
//

// Include files
#include "makeCell.h"
#include "RATMain_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  void b_makeCell(double m, ::coder::array<cell_wrap_9, 2U> &x)
  {
    int i;

    //  Creates a m by n cell array and initialise each cell with the given value.
    //
    //  Parameters
    //  ----------
    //  m, n : int
    //      The dimension of the array.
    //  vals : array
    //     The values to fill the cell array with.
    //
    //  Returns
    //  -------
    //  x : array
    //      The required cell array.
    //
    //  Examples
    //  --------
    //  >>> array = makeCell(5, 2, [1, 1])
    i = static_cast<int>(m);
    x.set_size(i, 2);
    for (int b_i{0}; b_i < i; b_i++) {
      for (int j{0}; j < 2; j++) {
        x[b_i + x.size(0) * j].f1.set_size(1, 3);
        x[b_i + x.size(0) * j].f1[0] = 0.0;
        x[b_i + x.size(0) * j].f1[x[b_i + x.size(0) * j].f1.size(0)] = 0.0;
        x[b_i + x.size(0) * j].f1[x[b_i + x.size(0) * j].f1.size(0) * 2] = 0.0;
      }
    }
  }

  void makeCell(cell_wrap_9 x[50])
  {
    //  Creates a m by n cell array and initialise each cell with the given value.
    //
    //  Parameters
    //  ----------
    //  m, n : int
    //      The dimension of the array.
    //  vals : array
    //     The values to fill the cell array with.
    //
    //  Returns
    //  -------
    //  x : array
    //      The required cell array.
    //
    //  Examples
    //  --------
    //  >>> array = makeCell(5, 2, [1, 1])
    x[0].f1.set_size(1, 1);
    x[0].f1[0] = 1.0;
    x[1].f1.set_size(1, 1);
    x[1].f1[0] = 1.0;
    x[2].f1.set_size(1, 1);
    x[2].f1[0] = 1.0;
    x[3].f1.set_size(1, 1);
    x[3].f1[0] = 1.0;
    x[4].f1.set_size(1, 1);
    x[4].f1[0] = 1.0;
    x[5].f1.set_size(1, 1);
    x[5].f1[0] = 1.0;
    x[6].f1.set_size(1, 1);
    x[6].f1[0] = 1.0;
    x[7].f1.set_size(1, 1);
    x[7].f1[0] = 1.0;
    x[8].f1.set_size(1, 1);
    x[8].f1[0] = 1.0;
    x[9].f1.set_size(1, 1);
    x[9].f1[0] = 1.0;
    x[10].f1.set_size(1, 1);
    x[10].f1[0] = 1.0;
    x[11].f1.set_size(1, 1);
    x[11].f1[0] = 1.0;
    x[12].f1.set_size(1, 1);
    x[12].f1[0] = 1.0;
    x[13].f1.set_size(1, 1);
    x[13].f1[0] = 1.0;
    x[14].f1.set_size(1, 1);
    x[14].f1[0] = 1.0;
    x[15].f1.set_size(1, 1);
    x[15].f1[0] = 1.0;
    x[16].f1.set_size(1, 1);
    x[16].f1[0] = 1.0;
    x[17].f1.set_size(1, 1);
    x[17].f1[0] = 1.0;
    x[18].f1.set_size(1, 1);
    x[18].f1[0] = 1.0;
    x[19].f1.set_size(1, 1);
    x[19].f1[0] = 1.0;
    x[20].f1.set_size(1, 1);
    x[20].f1[0] = 1.0;
    x[21].f1.set_size(1, 1);
    x[21].f1[0] = 1.0;
    x[22].f1.set_size(1, 1);
    x[22].f1[0] = 1.0;
    x[23].f1.set_size(1, 1);
    x[23].f1[0] = 1.0;
    x[24].f1.set_size(1, 1);
    x[24].f1[0] = 1.0;
    x[25].f1.set_size(1, 1);
    x[25].f1[0] = 1.0;
    x[26].f1.set_size(1, 1);
    x[26].f1[0] = 1.0;
    x[27].f1.set_size(1, 1);
    x[27].f1[0] = 1.0;
    x[28].f1.set_size(1, 1);
    x[28].f1[0] = 1.0;
    x[29].f1.set_size(1, 1);
    x[29].f1[0] = 1.0;
    x[30].f1.set_size(1, 1);
    x[30].f1[0] = 1.0;
    x[31].f1.set_size(1, 1);
    x[31].f1[0] = 1.0;
    x[32].f1.set_size(1, 1);
    x[32].f1[0] = 1.0;
    x[33].f1.set_size(1, 1);
    x[33].f1[0] = 1.0;
    x[34].f1.set_size(1, 1);
    x[34].f1[0] = 1.0;
    x[35].f1.set_size(1, 1);
    x[35].f1[0] = 1.0;
    x[36].f1.set_size(1, 1);
    x[36].f1[0] = 1.0;
    x[37].f1.set_size(1, 1);
    x[37].f1[0] = 1.0;
    x[38].f1.set_size(1, 1);
    x[38].f1[0] = 1.0;
    x[39].f1.set_size(1, 1);
    x[39].f1[0] = 1.0;
    x[40].f1.set_size(1, 1);
    x[40].f1[0] = 1.0;
    x[41].f1.set_size(1, 1);
    x[41].f1[0] = 1.0;
    x[42].f1.set_size(1, 1);
    x[42].f1[0] = 1.0;
    x[43].f1.set_size(1, 1);
    x[43].f1[0] = 1.0;
    x[44].f1.set_size(1, 1);
    x[44].f1[0] = 1.0;
    x[45].f1.set_size(1, 1);
    x[45].f1[0] = 1.0;
    x[46].f1.set_size(1, 1);
    x[46].f1[0] = 1.0;
    x[47].f1.set_size(1, 1);
    x[47].f1[0] = 1.0;
    x[48].f1.set_size(1, 1);
    x[48].f1[0] = 1.0;
    x[49].f1.set_size(1, 1);
    x[49].f1[0] = 1.0;
  }

  void makeCell(double m, ::coder::array<cell_wrap_9, 2U> &x)
  {
    int i;

    //  Creates a m by n cell array and initialise each cell with the given value.
    //
    //  Parameters
    //  ----------
    //  m, n : int
    //      The dimension of the array.
    //  vals : array
    //     The values to fill the cell array with.
    //
    //  Returns
    //  -------
    //  x : array
    //      The required cell array.
    //
    //  Examples
    //  --------
    //  >>> array = makeCell(5, 2, [1, 1])
    i = static_cast<int>(m);
    x.set_size(i, 1);
    for (int b_i{0}; b_i < i; b_i++) {
      x[b_i].f1.set_size(1, 3);
      x[b_i].f1[0] = 0.0;
      x[b_i].f1[x[b_i].f1.size(0)] = 0.0;
      x[b_i].f1[x[b_i].f1.size(0) * 2] = 0.0;
    }
  }
}

// End of code generation (makeCell.cpp)
