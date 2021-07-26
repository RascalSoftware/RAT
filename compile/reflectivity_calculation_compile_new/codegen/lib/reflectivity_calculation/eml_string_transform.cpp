//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// eml_string_transform.cpp
//
// Code generation for function 'eml_string_transform'
//

// Include files
#include "eml_string_transform.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static const char cv[128]{
    '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
    '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10', '\x11',
    '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
    '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
    '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
    '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
    '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
    '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
    'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
    'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
    'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
    'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
    'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
    'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
    '~',    '\x7f'};

// Function Definitions
namespace coder {
void eml_string_transform(const ::coder::array<char, 2U> &x,
                          ::coder::array<char, 2U> &y)
{
  int i;
  y.set_size(1, x.size(1));
  i = x.size(1);
  for (int k{0}; k < i; k++) {
    y[k] = cv[static_cast<unsigned char>(x[k]) & 127];
  }
}

char eml_string_transform(char x)
{
  return cv[static_cast<unsigned char>(x) & 127];
}

} // namespace coder

// End of code generation (eml_string_transform.cpp)
