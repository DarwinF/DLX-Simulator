using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace DLX_Editor
{
  class interpreter
  {
    private List<string> assembly_lines;
    private List<UInt32> binary_lines;
    private constants c = new constants();  

    public List<UInt32> BinaryLines
    {
      get
      {
        return binary_lines;
      }
    }

    public interpreter(List<string> lines)
    {
      assembly_lines = lines;
    }

    // Converts assembly lines to binary
    // Returns the number of lines converted
    public int ConvertASMtoBIN()
    {
      int lines_converted = 0;

      foreach (string l in assembly_lines)
        lines_converted += HandleLine(l);

      return lines_converted;
    }

    // Types of lines
    //    1. Comments (ignore) - start with //
    //    2. Assembly Instructions
    //    3. Non-Assembly Instructions
    private int HandleLine(string line)
    {
      int success = 0;

      if (line[0] == '/' || line[0] == '\n')
        success = 1;
      else
        success = ConvertBinary(line);

      return success;
    }

    private int ConvertBinary(string line)
    {
      int success = 0;
      string new_line = line.ToLower();

      string[] split = Regex.Split(new_line, @"\s+");

      UInt32 instruction = c.opcodes[split[0]];
      instruction <<= 26;
      
      instruction |= ProcessArguments(line.Replace(split[0], ""));

      binary_lines.Add(instruction);

      return success;
    }

    private UInt32 ProcessArguments(string line)
    {
      StringSplitOptions opts = StringSplitOptions.RemoveEmptyEntries;
      char[] seperators = new char[1];
      seperators[0] = ',';

      string args_nws = Regex.Replace(line, @"\s+", "");
      string[] args = args_nws.Split(seperators, opts);

      return 0;
    }
  }
}
