using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MatchingGame
{
    public partial class MainForm : Form
    {
        Random random = new Random();
        int counter = 0;
        int levels = 0;
        int timeLeft = 60;

        public MainForm()
        {
            InitializeComponent();
            textBox2.Text = "0" + levels;
            textBox1.Text = timeLeft + " seconds";
        }

       private void AssignIconsToSquares()
        {
            List<string> icons = new List<string>(){
                "!", "N", ",", "k", "b", "v", "w", "z", 
                "!", "N", ",", "k", "b", "v", "w", "z"
            };
            foreach (Control control in tableLayoutPanel2.Controls)
            {
                //MessageBox.Show("New Message");
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

        private void label_click(object sender, EventArgs e){
            Label clickedLabel = sender as Label;
            if (clickedLabel.ForeColor != Color.Black)
            {
                clickedLabel.ForeColor = Color.Black;

                if (firstClick == null || clickedLabel == firstClick)
                {
                    firstClick = clickedLabel;
                    return;
                }

                secondClick = clickedLabel;

                if (firstClick.Text == secondClick.Text)
                {
                    firstClick.ForeColor = Color.Black;
                    secondClick.ForeColor = Color.Black;

                    firstClick = null;
                    secondClick = null;
                    counter++;

                    if (counter >= 8)
                    {
                        MessageBox.Show("You have completed this level!!\nClick Start to  play the next level.");
                        textBox2.Text = "0" + (++levels);
                        timer2.Stop();
                        timeLeft = 60 - (5 * levels);
                        textBox1.Text = timeLeft + " seconds";
                    }
                }
                else
                {
                    timer1.Start();
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            timer1.Stop();
            firstClick.ForeColor = firstClick.BackColor;
            secondClick.ForeColor = secondClick.BackColor;
            firstClick = null;
            secondClick = null;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AssignIconsToSquares();
            timer2.Start();
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            if (timeLeft > 0)
            {
                textBox1.Text = (--timeLeft) + " seconds";
            }
            else
            {
                timer2.Stop();
                MessageBox.Show("You failed to complete this level!!");
                timeLeft = 60 - (levels * 5);
            }
        }

    }
}
