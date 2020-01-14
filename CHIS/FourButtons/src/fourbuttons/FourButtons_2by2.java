package fourbuttons;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JSeparator;
import com.jgoodies.forms.layout.FormLayout;
import com.jgoodies.forms.layout.ColumnSpec;
import com.jgoodies.forms.layout.RowSpec;
import com.jgoodies.forms.layout.FormSpecs;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class FourButtons_2by2 extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	public enum states { S0, S1, S2, S3, S4, S5 };
	public states s;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					FourButtons_2by2 frame = new FourButtons_2by2();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public void twoFirstActivate(JButton button1, JButton button2, JButton button3, JButton button4) {
		button1.setEnabled(true);
		button2.setEnabled(true);
		button3.setEnabled(false);
		button4.setEnabled(false);
	}

	public void twoLastActivate(JButton button1, JButton button2, JButton button3, JButton button4) {
		button1.setEnabled(false);
		button2.setEnabled(false);
		button3.setEnabled(true);
		button4.setEnabled(true);		
	}

	/**
	 * Create the frame.
	 */
	public FourButtons_2by2() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);

		s = states.S0;
		JButton btnNewButton = new JButton("B1");
		contentPane.add(btnNewButton, "4, 4");
		
		JButton btnNewButton_1 = new JButton("B2");
		contentPane.add(btnNewButton_1, "16, 4");
		
		JButton btnNewButton_2 = new JButton("B3");
		btnNewButton_2.setEnabled(false);
		contentPane.add(btnNewButton_2, "4, 14");
		
		JButton btnNewButton_3 = new JButton("B4");
		btnNewButton_3.setEnabled(false);
		contentPane.add(btnNewButton_3, "16, 14");

		btnNewButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				switch(s) {
					case S0:
						s = states.S1;
						twoFirstActivate(btnNewButton, btnNewButton_1, btnNewButton_2, btnNewButton_3);
						break;
					case S2:
						s = states.S3;
						twoLastActivate(btnNewButton, btnNewButton_1, btnNewButton_2, btnNewButton_3);
						break;
					default:
						break;
				}
			}
		});
	
		btnNewButton_1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				switch(s) {
					case S0:
						s = states.S2;
						twoFirstActivate(btnNewButton, btnNewButton_1, btnNewButton_2, btnNewButton_3);
						break;
					case S1:
						s = states.S3;
						twoLastActivate(btnNewButton, btnNewButton_1, btnNewButton_2, btnNewButton_3);
						break;
					default:
						break;
				}
			}
		});

		btnNewButton_2.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				switch(s) {
					case S3:
						s = states.S4;
						twoFirstActivate(btnNewButton, btnNewButton_1, btnNewButton_2, btnNewButton_3);
						break;
					case S5:
						s = states.S0;
						twoLastActivate(btnNewButton, btnNewButton_1, btnNewButton_2, btnNewButton_3);
						break;
					default:
						break;
				}
			}
		});
		
		btnNewButton_3.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				switch(s) {
					case S3:
						s = states.S5;
						twoFirstActivate(btnNewButton, btnNewButton_1, btnNewButton_2, btnNewButton_3);
						break;
					case S4:
						s = states.S0;
						twoLastActivate(btnNewButton, btnNewButton_1, btnNewButton_2, btnNewButton_3);
						break;
					default:
						break;
				}
			}
		});
	}

}
