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
    public partial class Form1 : Form
    {
        int timeLeft = 60;
        int level = 0;
        int counter = -1;
        Label firstClick = null;
        Label secondClick = null;


        Random random = new Random();
/*
        List<string> iconsTemp;

        List<string> icons = new List<string>(){
            "!", "N", ",", "k", "b", "v", "w", "z",
            "!", "N", ",", "k", "b", "v", "w", "z"
        };
        */
        public Form1()
        {
            InitializeComponent();           
        }

        //================================================
        //============ INITIALIZE METHODS ================
        //================================================

        //HIDES ALL THE UNMATHCED ICONS
        private void hideIcons()
        {
            foreach (Control control in tableLayoutPanel2.Controls)
            {
                Label iconLabel = control as Label;

                if (iconLabel != null && control.ForeColor != Color.Gray)
                {
                    iconLabel.ForeColor = iconLabel.BackColor;                   
                }
            }
        }

        //SHOWS ALL THE ICONS FOR 2 SECONDS
        private void showIcons()
        {
            foreach (Control control in tableLayoutPanel2.Controls)
            {
                Label iconLabel = control as Label;

                if (iconLabel != null && control.ForeColor != Color.Gray)
                {
                    iconLabel.ForeColor = Color.Black;
                }
                // firstClick = iconLabel;
                // secondClick = iconLabel;
            }
            timer3.Start();

        }

        //INITIALIZEZ ALL THE ICONS AND HIDE THEM
        private void AssignIconsToSquires()
        {

            List<string> icons = new List<string>(){
            "!", "N", ",", "k", "b", "v", "w", "z",
            "!", "N", ",", "k", "b", "v", "w", "z"
            };
            
            foreach (Control control in tableLayoutPanel2.Controls)
            {
                Label iconLabel = control as Label;

                if (iconLabel != null)
                {                    
                    int randmoNumber = random.Next(icons.Count);
                    iconLabel.Text = icons[randmoNumber];
                    icons.RemoveAt(randmoNumber);
                    iconLabel.BackColor = Color.SkyBlue;
                    iconLabel.ForeColor = iconLabel.BackColor;
                }
            }
            firstClick = null;
            secondClick = null;
        }


        //================================================
        //================= TIMERS =======================
        //================================================

        //for showing tow icons for 1.5 seconds
        private void timer1_Tick(object sender, EventArgs e)
        {
            timer1.Stop();
            firstClick.ForeColor = firstClick.BackColor;
            secondClick.ForeColor = secondClick.BackColor;
            firstClick = null;
            secondClick = null;
        }

        //entire level time
        private void timer2_Tick(object sender, EventArgs e)
        {
            if (timeLeft > 0)
            {
                timeText.Text = --timeLeft + " Seconds";
            }
            else
            {
                timer2.Stop();
                MessageBox.Show("You failed to complete this level");
                counter = -1;
                AssignIconsToSquires();
                timeLeft = 60 - (level * 5);
            }
        }

        //for 2 second preview
        private void timer3_Tick(object sender, EventArgs e)
        {
            timer3.Stop();
            hideIcons();
        }

        //================================================
        //================= BUTTONS  =====================
        //================================================

        //START THE GAME
        private void startButton_Click(object sender, EventArgs e)
        {
            if (counter >= 0)
                return;

            AssignIconsToSquires();
            counter = 0;            
            //MessageBox.Show(" "+timeLeft);            
            showIcons();
            timer2.Start();
        }

        //PREVIEW ALL ICONS FOR 2 SECONDS AND SUB 5 SECONDS FROM THE TIMER
        private void previewButton_Click(object sender, EventArgs e)
        {
            showIcons();
            timeLeft -= 5;
        }

        //END THE GAME
        private void endButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        //LABEL CLICK EVENT
        private void label_Click(object sender, EventArgs e)
        {
            Label clickLabel = sender as Label;

            if (clickLabel != null && counter >= 0)
            {
                if (clickLabel.ForeColor == Color.Gray || firstClick == clickLabel)
                    return;

                if (firstClick == null)
                {
                    firstClick = clickLabel;
                    firstClick.ForeColor = Color.Black;
                    return;
                }
                else
                {
                    secondClick = clickLabel;
                    secondClick.ForeColor = Color.Black;
                }

                if (firstClick.Text == secondClick.Text)
                {
                    firstClick.BackColor = Color.White;
                    secondClick.BackColor = Color.White;
                    firstClick.ForeColor = Color.Gray;
                    secondClick.ForeColor = Color.Gray;

                    firstClick = null;
                    secondClick = null;
                    if (++counter >= 8)
                    {
                        MessageBox.Show("You completed level"+level+"!!\nPlease press Start to play the next level.");
                        counter = -1;
                        timeLeft = 60 - (++level * 5);
                        levelCounter.Text = "0" + level;
                        timer2.Stop();
                    }
                }
                else
                {
                    timer1.Start();
                }
            }
        }
    }
}
