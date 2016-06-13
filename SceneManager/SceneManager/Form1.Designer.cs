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
            this.NewButton = new System.Windows.Forms.Button();
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
            this.GOName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.DeleteButton = new System.Windows.Forms.Button();
            this.ExitButton = new System.Windows.Forms.Button();
            this.RunButton = new System.Windows.Forms.Button();
            this.lightShaderTypeCombo = new System.Windows.Forms.ComboBox();
            this.label16 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.gameObjectsGrid)).BeginInit();
            this.SuspendLayout();
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // NewButton
            // 
            this.NewButton.Location = new System.Drawing.Point(546, 75);
            this.NewButton.Name = "NewButton";
            this.NewButton.Size = new System.Drawing.Size(68, 30);
            this.NewButton.TabIndex = 1;
            this.NewButton.Text = "New";
            this.NewButton.UseVisualStyleBackColor = true;
            this.NewButton.Click += new System.EventHandler(this.button2_Click);
            // 
            // nameText
            // 
            this.nameText.Location = new System.Drawing.Point(386, 12);
            this.nameText.Name = "nameText";
            this.nameText.Size = new System.Drawing.Size(228, 20);
            this.nameText.TabIndex = 2;
            this.nameText.TextChanged += new System.EventHandler(this.nameText_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(321, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(321, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Position";
            // 
            // positionXText
            // 
            this.positionXText.Location = new System.Drawing.Point(386, 75);
            this.positionXText.Name = "positionXText";
            this.positionXText.Size = new System.Drawing.Size(42, 20);
            this.positionXText.TabIndex = 4;
            this.positionXText.TextChanged += new System.EventHandler(this.positionXText_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(401, 60);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(12, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "x";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(450, 60);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(12, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "y";
            // 
            // positionYText
            // 
            this.positionYText.Location = new System.Drawing.Point(435, 75);
            this.positionYText.Name = "positionYText";
            this.positionYText.Size = new System.Drawing.Size(42, 20);
            this.positionYText.TabIndex = 7;
            this.positionYText.TextChanged += new System.EventHandler(this.positionYText_TextChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(498, 60);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(12, 13);
            this.label5.TabIndex = 10;
            this.label5.Text = "z";
            // 
            // positionZText
            // 
            this.positionZText.Location = new System.Drawing.Point(483, 75);
            this.positionZText.Name = "positionZText";
            this.positionZText.Size = new System.Drawing.Size(42, 20);
            this.positionZText.TabIndex = 9;
            this.positionZText.TextChanged += new System.EventHandler(this.positionZText_TextChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(498, 98);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(12, 13);
            this.label6.TabIndex = 17;
            this.label6.Text = "z";
            // 
            // rotationZText
            // 
            this.rotationZText.Location = new System.Drawing.Point(483, 114);
            this.rotationZText.Name = "rotationZText";
            this.rotationZText.Size = new System.Drawing.Size(42, 20);
            this.rotationZText.TabIndex = 16;
            this.rotationZText.TextChanged += new System.EventHandler(this.rotationZText_TextChanged);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(450, 98);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(12, 13);
            this.label7.TabIndex = 15;
            this.label7.Text = "y";
            // 
            // rotationYText
            // 
            this.rotationYText.Location = new System.Drawing.Point(435, 114);
            this.rotationYText.Name = "rotationYText";
            this.rotationYText.Size = new System.Drawing.Size(42, 20);
            this.rotationYText.TabIndex = 14;
            this.rotationYText.TextChanged += new System.EventHandler(this.rotationYText_TextChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(401, 98);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(12, 13);
            this.label8.TabIndex = 13;
            this.label8.Text = "x";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(321, 117);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(47, 13);
            this.label9.TabIndex = 12;
            this.label9.Text = "Rotation";
            // 
            // rotationXText
            // 
            this.rotationXText.Location = new System.Drawing.Point(386, 114);
            this.rotationXText.Name = "rotationXText";
            this.rotationXText.Size = new System.Drawing.Size(42, 20);
            this.rotationXText.TabIndex = 11;
            this.rotationXText.TextChanged += new System.EventHandler(this.rotationXText_TextChanged);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(498, 133);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(12, 13);
            this.label10.TabIndex = 24;
            this.label10.Text = "z";
            // 
            // scaleZText
            // 
            this.scaleZText.Location = new System.Drawing.Point(483, 149);
            this.scaleZText.Name = "scaleZText";
            this.scaleZText.Size = new System.Drawing.Size(42, 20);
            this.scaleZText.TabIndex = 23;
            this.scaleZText.TextChanged += new System.EventHandler(this.scaleZText_TextChanged);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(450, 133);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(12, 13);
            this.label11.TabIndex = 22;
            this.label11.Text = "y";
            // 
            // scaleYText
            // 
            this.scaleYText.Location = new System.Drawing.Point(435, 149);
            this.scaleYText.Name = "scaleYText";
            this.scaleYText.Size = new System.Drawing.Size(42, 20);
            this.scaleYText.TabIndex = 21;
            this.scaleYText.TextChanged += new System.EventHandler(this.scaleYText_TextChanged);
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(401, 133);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(12, 13);
            this.label12.TabIndex = 20;
            this.label12.Text = "x";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(321, 152);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(34, 13);
            this.label13.TabIndex = 19;
            this.label13.Text = "Scale";
            // 
            // scaleXText
            // 
            this.scaleXText.Location = new System.Drawing.Point(386, 149);
            this.scaleXText.Name = "scaleXText";
            this.scaleXText.Size = new System.Drawing.Size(42, 20);
            this.scaleXText.TabIndex = 18;
            this.scaleXText.TextChanged += new System.EventHandler(this.scaleXText_TextChanged);
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(321, 42);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(60, 13);
            this.label14.TabIndex = 25;
            this.label14.Text = "Model path";
            // 
            // modelPathText
            // 
            this.modelPathText.Location = new System.Drawing.Point(386, 39);
            this.modelPathText.Name = "modelPathText";
            this.modelPathText.Size = new System.Drawing.Size(194, 20);
            this.modelPathText.TabIndex = 26;
            this.modelPathText.TextChanged += new System.EventHandler(this.modelPathText_TextChanged);
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(321, 181);
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
            this.shaderTypeCombo.Location = new System.Drawing.Point(386, 178);
            this.shaderTypeCombo.Name = "shaderTypeCombo";
            this.shaderTypeCombo.Size = new System.Drawing.Size(139, 21);
            this.shaderTypeCombo.TabIndex = 28;
            this.shaderTypeCombo.Text = "StandardShader";
            this.shaderTypeCombo.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // gameObjectsGrid
            // 
            this.gameObjectsGrid.AllowUserToAddRows = false;
            this.gameObjectsGrid.AllowUserToDeleteRows = false;
            this.gameObjectsGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gameObjectsGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.GOName});
            this.gameObjectsGrid.Location = new System.Drawing.Point(12, 12);
            this.gameObjectsGrid.Name = "gameObjectsGrid";
            this.gameObjectsGrid.ReadOnly = true;
            this.gameObjectsGrid.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.gameObjectsGrid.RowHeadersVisible = false;
            this.gameObjectsGrid.Size = new System.Drawing.Size(295, 200);
            this.gameObjectsGrid.TabIndex = 31;
            this.gameObjectsGrid.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.gameObjectsGrid_CellClick);
            this.gameObjectsGrid.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.gameObjectsGrid_CellContentClick);
            // 
            // GOName
            // 
            this.GOName.HeaderText = "Name";
            this.GOName.Name = "GOName";
            this.GOName.ReadOnly = true;
            this.GOName.Width = 290;
            // 
            // DeleteButton
            // 
            this.DeleteButton.Location = new System.Drawing.Point(546, 112);
            this.DeleteButton.Name = "DeleteButton";
            this.DeleteButton.Size = new System.Drawing.Size(68, 30);
            this.DeleteButton.TabIndex = 33;
            this.DeleteButton.Text = "Delete";
            this.DeleteButton.UseVisualStyleBackColor = true;
            this.DeleteButton.Click += new System.EventHandler(this.button3_Click);
            // 
            // ExitButton
            // 
            this.ExitButton.Location = new System.Drawing.Point(546, 186);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(68, 30);
            this.ExitButton.TabIndex = 34;
            this.ExitButton.Text = "Exit";
            this.ExitButton.UseVisualStyleBackColor = true;
            this.ExitButton.Click += new System.EventHandler(this.button4_Click);
            // 
            // RunButton
            // 
            this.RunButton.Location = new System.Drawing.Point(546, 149);
            this.RunButton.Name = "RunButton";
            this.RunButton.Size = new System.Drawing.Size(68, 30);
            this.RunButton.TabIndex = 35;
            this.RunButton.Text = "Run scene";
            this.RunButton.UseVisualStyleBackColor = true;
            this.RunButton.Click += new System.EventHandler(this.button5_Click);
            // 
            // lightShaderTypeCombo
            // 
            this.lightShaderTypeCombo.FormattingEnabled = true;
            this.lightShaderTypeCombo.Items.AddRange(new object[] {
            "Directional",
            "Point",
            "Spot"});
            this.lightShaderTypeCombo.Location = new System.Drawing.Point(385, 197);
            this.lightShaderTypeCombo.Name = "lightShaderTypeCombo";
            this.lightShaderTypeCombo.Size = new System.Drawing.Size(139, 21);
            this.lightShaderTypeCombo.TabIndex = 36;
            this.lightShaderTypeCombo.Text = "Directional";
            this.lightShaderTypeCombo.SelectedIndexChanged += new System.EventHandler(this.lightShaderTypeCombo_SelectedIndexChanged);
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(321, 200);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(53, 13);
            this.label16.TabIndex = 37;
            this.label16.Text = "Light type";
            this.label16.Visible = false;
            // 
            // button1
            // 
            this.button1.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.button1.Location = new System.Drawing.Point(581, 39);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(33, 20);
            this.button1.TabIndex = 38;
            this.button1.Text = "Set";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(626, 227);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label16);
            this.Controls.Add(this.lightShaderTypeCombo);
            this.Controls.Add(this.RunButton);
            this.Controls.Add(this.ExitButton);
            this.Controls.Add(this.DeleteButton);
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
            this.Controls.Add(this.NewButton);
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
        private System.Windows.Forms.Button NewButton;
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
        private System.Windows.Forms.Button DeleteButton;
        private System.Windows.Forms.Button ExitButton;
        private System.Windows.Forms.Button RunButton;
        private System.Windows.Forms.ComboBox lightShaderTypeCombo;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.DataGridViewTextBoxColumn GOName;
        private System.Windows.Forms.Button button1;
    }
}

