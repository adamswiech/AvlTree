using projekt_Kamil.Modules;

namespace projekt_Kamil
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

        }


        private void button1_Click(object sender, EventArgs e)
        {
            bool relOnes = checkBox1.Checked;
            int quantity = (int)numericUpDown1.Value;
            int attacks = (int)numericUpDown6.Value;
            int S = (int)numericUpDown2.Value;
            int T = (int)numericUpDown3.Value;
            int AP = (int)numericUpDown4.Value;
            int Sv = (int)numericUpDown5.Value;
            ClassicThrow a = new ClassicThrow();

            this.richTextBox1.Text = a.Calkulate(quantity, attacks, relOnes,S,T,AP,Sv);
            //this.richTextBox1.Text = attacks.ToString();
        }


    }
}
