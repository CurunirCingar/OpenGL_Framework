namespace SceneManager
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.button2 = new System.Windows.Forms.Button();
            this.nameText = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.positionXText = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.positionYText = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.positionZText = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.rotationZText = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.rotationYText = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.rotationXText = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.scaleZText = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.scaleYText = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.scaleXText = new System.Windows.Forms.TextBox();
            this.label14 = new System.Windows.Forms.Label();
            this.modelPathText = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.shaderTypeCombo = new System.Windows.Forms.ComboBox();
            this.gameObjectsGrid = new System.Windows.Forms.DataGridView();
            this.ID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.GOName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.button1 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.lightShaderTypeCombo = new System.Windows.Forms.ComboBox();
            this.label16 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.gameObjectsGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(229, 242);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(56, 30);
            this.button2.TabIndex = 1;
            this.button2.Text = "New";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // nameText
            // 
            this.nameText.Location = new System.Drawing.Point(75, 12);
            this.nameText.Name = "nameText";
            this.nameText.Size = new System.Drawing.Size(138, 20);
            this.nameText.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(10, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(10, 53);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Position";
            // 
            // positionXText
            // 
            this.positionXText.Location = new System.Drawing.Point(75, 50);
            this.positionXText.Name = "positionXText";
            this.positionXText.Size = new System.Drawing.Size(42, 20);
            this.positionXText.TabIndex = 4;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(90, 35);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(12, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "x";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(139, 35);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(12, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "y";
            // 
            // positionYText
            // 
            this.positionYText.Location = new System.Drawing.Point(124, 50);
            this.positionYText.Name = "positionYText";
            this.positionYText.Size = new System.Drawing.Size(42, 20);
            this.positionYText.TabIndex = 7;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(187, 35);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(12, 13);
            this.label5.TabIndex = 10;
            this.label5.Text = "z";
            // 
            // positionZText
            // 
            this.positionZText.Location = new System.Drawing.Point(172, 50);
            this.positionZText.Name = "positionZText";
            this.positionZText.Size = new System.Drawing.Size(42, 20);
            this.positionZText.TabIndex = 9;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(187, 73);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(12, 13);
            this.label6.TabIndex = 17;
            this.label6.Text = "z";
            // 
            // rotationZText
            // 
            this.rotationZText.Location = new System.Drawing.Point(172, 89);
            this.rotationZText.Name = "rotationZText";
            this.rotationZText.Size = new System.Drawing.Size(42, 20);
            this.rotationZText.TabIndex = 16;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(139, 73);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(12, 13);
            this.label7.TabIndex = 15;
            this.label7.Text = "y";
            // 
            // rotationYText
            // 
            this.rotationYText.Location = new System.Drawing.Point(124, 89);
            this.rotationYText.Name = "rotationYText";
            this.rotationYText.Size = new System.Drawing.Size(42, 20);
            this.rotationYText.TabIndex = 14;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(90, 73);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(12, 13);
            this.label8.TabIndex = 13;
            this.label8.Text = "x";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(10, 92);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(47, 13);
            this.label9.TabIndex = 12;
            this.label9.Text = "Rotation";
            // 
            // rotationXText
            // 
            this.rotationXText.Location = new System.Drawing.Point(75, 89);
            this.rotationXText.Name = "rotationXText";
            this.rotationXText.Size = new System.Drawing.Size(42, 20);
            this.rotationXText.TabIndex = 11;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(187, 108);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(12, 13);
            this.label10.TabIndex = 24;
            this.label10.Text = "z";
            // 
            // scaleZText
            // 
            this.scaleZText.Location = new System.Drawing.Point(172, 124);
            this.scaleZText.Name = "scaleZText";
            this.scaleZText.Size = new System.Drawing.Size(42, 20);
            this.scaleZText.TabIndex = 23;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(139, 108);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(12, 13);
            this.label11.TabIndex = 22;
            this.label11.Text = "y";
            // 
            // scaleYText
            // 
            this.scaleYText.Location = new System.Drawing.Point(124, 124);
            this.scaleYText.Name = "scaleYText";
            this.scaleYText.Size = new System.Drawing.Size(42, 20);
            this.scaleYText.TabIndex = 21;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(90, 108);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(12, 13);
            this.label12.TabIndex = 20;
            this.label12.Text = "x";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(10, 127);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(34, 13);
            this.label13.TabIndex = 19;
            this.label13.Text = "Scale";
            // 
            // scaleXText
            // 
            this.scaleXText.Location = new System.Drawing.Point(75, 124);
            this.scaleXText.Name = "scaleXText";
            this.scaleXText.Size = new System.Drawing.Size(42, 20);
            this.scaleXText.TabIndex = 18;
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(10, 162);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(60, 13);
            this.label14.TabIndex = 25;
            this.label14.Text = "Model path";
            // 
            // modelPathText
            // 
            this.modelPathText.Location = new System.Drawing.Point(75, 159);
            this.modelPathText.Name = "modelPathText";
            this.modelPathText.Size = new System.Drawing.Size(139, 20);
            this.modelPathText.TabIndex = 26;
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(10, 199);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(64, 13);
            this.label15.TabIndex = 27;
            this.label15.Text = "Shader type";
            // 
            // shaderTypeCombo
            // 
            this.shaderTypeCombo.FormattingEnabled = true;
            this.shaderTypeCombo.Items.AddRange(new object[] {
            "StandardShader",
            "LightShader"});
            this.shaderTypeCombo.Location = new System.Drawing.Point(75, 196);
            this.shaderTypeCombo.Name = "shaderTypeCombo";
            this.shaderTypeCombo.Size = new System.Drawing.Size(139, 21);
            this.shaderTypeCombo.TabIndex = 28;
            this.shaderTypeCombo.Text = "StandardShader";
            this.shaderTypeCombo.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // gameObjectsGrid
            // 
            this.gameObjectsGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gameObjectsGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.ID,
            this.GOName});
            this.gameObjectsGrid.Location = new System.Drawing.Point(229, 12);
            this.gameObjectsGrid.Name = "gameObjectsGrid";
            this.gameObjectsGrid.ReadOnly = true;
            this.gameObjectsGrid.RowHeadersVisible = false;
            this.gameObjectsGrid.Size = new System.Drawing.Size(304, 205);
            this.gameObjectsGrid.TabIndex = 31;
            this.gameObjectsGrid.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.gameObjectsGrid_CellClick);
            this.gameObjectsGrid.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.gameObjectsGrid_CellContentClick);
            // 
            // ID
            // 
            this.ID.HeaderText = "ID";
            this.ID.Name = "ID";
            this.ID.Width = 40;
            // 
            // GOName
            // 
            this.GOName.HeaderText = "Name";
            this.GOName.Name = "GOName";
            this.GOName.Width = 250;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(13, 242);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(89, 30);
            this.button1.TabIndex = 32;
            this.button1.Text = "Save changes";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(291, 242);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(56, 30);
            this.button3.TabIndex = 33;
            this.button3.Text = "Delete";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(465, 242);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(64, 30);
            this.button4.TabIndex = 34;
            this.button4.Text = "Exit";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(391, 242);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(68, 30);
            this.button5.TabIndex = 35;
            this.button5.Text = "Run scene";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // lightShaderTypeCombo
            // 
            this.lightShaderTypeCombo.FormattingEnabled = true;
            this.lightShaderTypeCombo.Items.AddRange(new object[] {
            "Directional",
            "Point",
            "Spot"});
            this.lightShaderTypeCombo.Location = new System.Drawing.Point(74, 215);
            this.lightShaderTypeCombo.Name = "lightShaderTypeCombo";
            this.lightShaderTypeCombo.Size = new System.Drawing.Size(139, 21);
            this.lightShaderTypeCombo.TabIndex = 36;
            this.lightShaderTypeCombo.Text = "Directional";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(10, 218);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(53, 13);
            this.label16.TabIndex = 37;
            this.label16.Text = "Light type";
            this.label16.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(541, 281);
            this.Controls.Add(this.label16);
            this.Controls.Add(this.lightShaderTypeCombo);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.gameObjectsGrid);
            this.Controls.Add(this.shaderTypeCombo);
            this.Controls.Add(this.label15);
            this.Controls.Add(this.modelPathText);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.scaleZText);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.scaleYText);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.scaleXText);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.rotationZText);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.rotationYText);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.rotationXText);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.positionZText);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.positionYText);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.positionXText);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.nameText);
            this.Controls.Add(this.button2);
            this.Name = "Form1";
            this.Text = "SceneManager";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.gameObjectsGrid)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox nameText;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox positionXText;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox positionYText;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox positionZText;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox rotationZText;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox rotationYText;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox rotationXText;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox scaleZText;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox scaleYText;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox scaleXText;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox modelPathText;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.ComboBox shaderTypeCombo;
        private System.Windows.Forms.DataGridView gameObjectsGrid;
        private System.Windows.Forms.DataGridViewTextBoxColumn ID;
        private System.Windows.Forms.DataGridViewTextBoxColumn GOName;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.ComboBox lightShaderTypeCombo;
        private System.Windows.Forms.Label label16;
    }
}

