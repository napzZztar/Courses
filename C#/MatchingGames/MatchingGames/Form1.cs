using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MatchingGames
{
    public partial class MainForm : Form
    {
        List<string> icons = new List<string>()
        {
            "!", "!", "N", "N", ",", ",", "k", "k",
            "b", "b", "v", "v", "w", "w", "z", "z"
        };

        Random random = new Random();
        int counter = 0;
        public MainForm()
        {
            InitializeComponent();
            AssignIconsToSquares();
            timer2.Start();
        }

        private void AssignIconsToSquares()
        {
            foreach (Control control in tableLayoutPanel1.Controls)
            {
                Label iconLabel = control as Label;
                if (iconLabel != null)
                {
                    int randomNumber = random.Next(icons.Count);
                    iconLabel.Text = icons[randomNumber];
                    iconLabel.ForeColor = iconLabel.BackColor;
                    icons.RemoveAt(randomNumber);
                }
            }
        }

        Label firstClick;
        Label secondClick;

        private void label_click(object sender, EventArgs e)
        {
            Label clickedLabel = sender as Label;
             clickedLabel.ForeColor = Color.Black;

            if (firstClick == null)
            {
                firstClick = clickedLabel;                
                return;
            }

            secondClick = clickedLabel;    

            if (firstClick.Text == secondClick.Text)
            {
                firstClick.BackColor = Color.Black;
                firstClick.ForeColor = Color.White;
                secondClick.ForeColor = Color.White;
                secondClick.BackColor = Color.Black;

                firstClick = null;
                secondClick = null;
                counter++;
                if (counter == 8)
                    MessageBox.Show("You are done");
            }
            else
            {
                timer1.Start();                                
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            timer1.Stop();           
            firstClick.ForeColor = firstClick.BackColor;
            secondClick.ForeColor = firstClick.BackColor;
            firstClick = null;
            secondClick = null;
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            timer2.Stop();
            MessageBox.Show("Time out");
            //AssignIconsToSquares();
        }
    }
}
