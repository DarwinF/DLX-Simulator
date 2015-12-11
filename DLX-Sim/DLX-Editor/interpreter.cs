using System;
using System.Collections.Generic;
using System.ComponentModel;
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
      binary_lines = new List<uint>();
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

      if (line == "" || line[0] == '/' || line[0] == '\n')
        success = 1;
      else
        success = ConvertBinary(line);

      return success;
    }

    private int ConvertBinary(string line)
    {
      int success = 0;

      string opcode = Regex.Split(line.ToLower(), @"\s+")[0];
      string arguments = Regex.Replace(line.Replace(opcode, ""), @"\s+", "");

      UInt32 instruction = 0;
      UInt32 op = GetOpcode(opcode);
      UInt32 args = ProcessArguments(arguments);

      if (op == 0)
      {
        instruction |= args;
        instruction |= GetFuncCode(opcode);
      }
      else
      {
        instruction |= (op << 26);
        instruction |= args;
      }

      binary_lines.Add(instruction);

      return success;
    }

    private UInt32 ProcessArguments(string line)
    {
      string trimmed = Regex.Replace(line, @"\s+", "");
      string[] args = Regex.Split(trimmed, ",");

      UInt32 destination = 0;
      UInt32 source_one = 0;
      UInt32 source_two = 0;
      UInt32 response = 0;

      if (args.Length == 1)
        return GetValue(args[0]);

      source_one = GetRegister(args[1].Substring(1));
      destination = GetRegister(args[0].Substring(1));

      response = source_one << 21;

      // R-Type Instruction
      if (args[2][0] == 'r')
      {
        source_two = GetRegister(args[2].Substring(1));
        response |= (source_two << 16);
        response |= (destination << 11);
      }
      // I-Type Instruction
      else
      {
        source_two = GetValue(args[2]);
        response |= (destination << 16);
        response |= source_two;
      }

      return response;
    }

    private UInt32 GetOpcode(string opcode)
    {
      return c.opcodes[opcode];
    }

    private UInt32 GetFuncCode(string func_code)
    {
      return c.func_codes[func_code];
    }

    private UInt32 GetRegister(string register)
    {
      return UInt32.Parse(register);
    }

    private UInt32 GetValue(string value)
    {
      return UInt32.Parse(value);
    }
  }
}
