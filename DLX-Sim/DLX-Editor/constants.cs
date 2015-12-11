using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DLX_Editor
{
  class constants
  {
    public Dictionary<string, UInt32> opcodes = new Dictionary<string, uint>()
    {
      {"beqz",0x04}, {"bnez",0x05}, {"addi",0x08}, {"subi",0x0a }, {"andi",0x0c}, {"ori",0x0d}, {"xori",0x0e },
      {"lhi",0x0f }, {"jr", 0x12 }, {"jalr",0x13 }, {"slli", 0x014 }, {"srli",0x16 }, {"srai", 0x17 }, {"seqi", 0x18 },
      {"snei", 0x19 }, {"slti", 0x1a }, {"slei", 0x1c }, {"lw", 0x23 }, {"sw", 0x2b }, {"j", 0x02 }, {"jal", 0x03 },
      {"sll", 0x00 }, {"srl", 0x00}, {"sra", 0x00}, {"add", 0x00}, {"sub", 0x00}, {"and", 0x00}, {"or", 0x00},
      {"xor", 0x00 }, {"seq", 0x00 }, {"sne", 0x00 }, {"slt", 0x00 }, {"sle", 0x00 }
    };

    public Dictionary<string, UInt32> func_codes = new Dictionary<string, uint>()
    {
      {"sll", 0x04 }, {"srl", 0x06}, {"sra", 0x07}, {"add", 0x20}, {"sub", 0x22}, {"and", 0x24}, {"or", 0x25},
      {"xor", 0x26 }, {"seq", 0x28 }, {"sne", 0x29 }, {"slt", 0x2a }, {"sle", 0x2c }
    }; 
  }
}
