using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;
using System.Windows.Forms;

namespace Sqlite
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
            
           
            
        }

        private void cmdExecuteQuery_Click(object sender, EventArgs e)
        {
            SQLiteConnection myConnection = new SQLiteConnection("Data Source=C:\\sqlite\\database1.db3;Version=3");
            myConnection.Open();
            SQLiteCommand cmd = new SQLiteCommand();
            cmd.Connection = myConnection;
            cmd.CommandText = querytxt.Text;
            using (SQLiteDataReader sdr = cmd.ExecuteReader())
            {
                DataTable dt = new DataTable();
                dt.Load(sdr);
                sdr.Close();
                myConnection.Close();
                grid1.DataSource = dt;
            }

        }
    }
}
