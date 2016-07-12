package third_assignment;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.JCheckBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

@SuppressWarnings("serial")

public class StyleOptionsPanel extends JPanel
{
	private JLabel	saying;
	private JCheckBox	bold, italic;
	private JTextField input;

	public StyleOptionsPanel()
	{
		saying = new JLabel("Say it with style!");
		saying.setFont(new Font("Helvetica", Font.PLAIN, 36));

		bold = new JCheckBox("Bold");
		bold.setBackground(Color.cyan);
		italic = new JCheckBox("Italic");
		italic.setBackground(Color.cyan);
		
		input = new JTextField(5);
		input.setText("36");
		

		StyleListener listener = new StyleListener();
		bold.addItemListener(listener);
		italic.addItemListener(listener);

		add(saying);
		add(bold);
		add(italic);
		add(input);


		setBackground(Color.cyan);
		setPreferredSize(new Dimension(300, 100));
	}

	private class StyleListener implements ItemListener
	{
		public void itemStateChanged(ItemEvent event)
		{
			int style = Font.PLAIN;
			
			if (bold.isSelected())
				style += Font.BOLD;

			if (italic.isSelected())
				style += Font.ITALIC;
			
			int fontSize = Integer.parseInt(input.getText());
			
			saying.setFont(new Font("Helvetica", style, fontSize));
		}

	}
}

