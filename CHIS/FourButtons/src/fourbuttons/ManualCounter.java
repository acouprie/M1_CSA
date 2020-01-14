package fourbuttons;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JSplitPane;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class ManualCounter extends JFrame {

	private JPanel contentPane;
	public enum states { S0, S1 };
	public states s = states.S0;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ManualCounter frame = new ManualCounter();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public ManualCounter() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 146);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		JPanel panel = new JPanel();
		contentPane.add(panel, BorderLayout.NORTH);
		
		JLabel label = new JLabel("0");
		panel.add(label);
		
		JPanel panel_1 = new JPanel();
		contentPane.add(panel_1, BorderLayout.SOUTH);
		
		JButton btnStart = new JButton("Start");
		panel_1.add(btnStart);
		
		JButton btnStop = new JButton("Stop");

		btnStop.setEnabled(false);
		panel_1.add(btnStop);
		
		JButton button = new JButton("++");
		button.setEnabled(false);
		panel_1.add(button);

		btnStart.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				s = states.S1;
				label.setText("0");
				btnStart.setEnabled(false);
				btnStop.setEnabled(true);
				button.setEnabled(true);
			}
		});
		
		btnStop.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				s = states.S0;
				label.setText("0");
				btnStart.setEnabled(true);
				btnStop.setEnabled(false);
				button.setEnabled(false);
			}
		});
		
		button.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				int counter = Integer.parseInt(label.getText());
				if(counter == 3) {
					s = states.S1;
					label.setText("0");
					btnStart.setEnabled(false);
					btnStop.setEnabled(true);
					button.setEnabled(true);
				} else {
					s = states.S1;
					label.setText(Integer.toString(counter + 1));
					btnStart.setEnabled(false);
					btnStop.setEnabled(true);
					button.setEnabled(true);
				}
			}
		});
	}

}
