using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DLX_Editor
{
  static class Program
  {
    /// <summary>
    /// The main entry point for the application.
    /// </summary>
    [STAThread]
    static void Main()
    {
      //Application.EnableVisualStyles();
      //Application.SetCompatibleTextRenderingDefault(false);
      //Application.Run(new Form1());

      file_handler fh = new file_handler("../../test.txt");
      List<string> lines = fh.ReadFile();

      interpreter i = new interpreter(lines);
      i.ConvertASMtoBIN();
      fh.WriteFile("../../binary", i.BinaryLines);
    }
  }
}
