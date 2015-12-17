using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DLX_Editor
{
  class file_handler
  {
    private string file_location;
    private StreamReader file_reader;
    private BinaryWriter file_writer;

    public file_handler(string path)
    {
      file_location = path;
    }

    public List<string> ReadFile()
    {
      file_reader = new StreamReader(file_location);

      List<string> lines = new List<string>();
      string curr_line;

      while ((curr_line = file_reader.ReadLine()) != null)
        lines.Add(curr_line);

      file_reader.Close();
      return lines;
    }

    public void WriteFile(string path, List<UInt32> instructions)
    {
      file_writer = new BinaryWriter(File.Open(path, FileMode.Create));

      foreach (UInt32 i in instructions)
        file_writer.Write(i);

      // Print end symbol
      UInt32 end = 0x00;
      file_writer.Write(end);

      file_writer.Close();
    }
  }
}
