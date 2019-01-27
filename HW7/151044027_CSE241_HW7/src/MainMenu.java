import java.awt.EventQueue;
import java.awt.Graphics;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
/** 
 * 
 * @author Sushi
 *
 */
public class MainMenu {

	private JFrame frmPatoglushapegui;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainMenu window = new MainMenu();
					window.frmPatoglushapegui.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public MainMenu() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmPatoglushapegui = new JFrame();
		frmPatoglushapegui.setTitle("PatogluShapeGUI - 151044027");
		frmPatoglushapegui.setBounds(100, 100, 653, 546);
		frmPatoglushapegui.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmPatoglushapegui.getContentPane().setLayout(null);
		
		JButton btnTriangleTriangle = new JButton("Circle- Circle");
		btnTriangleTriangle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				CCGUI gui = new CCGUI();
				JFrame jf = new JFrame();
				jf.setTitle("Test");
				jf.setSize(1280,960);
				jf.setVisible(true);
				jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				jf.getContentPane().add(gui);
				StaticMethods.SortShapes();
				StaticMethods.drawAll();
				StaticMethods.convertAll();
			}
		});
		btnTriangleTriangle.setBounds(217, 391, 185, 29);
		frmPatoglushapegui.getContentPane().add(btnTriangleTriangle);
		
		JButton btnCircleTriangle = new JButton("Circle- Triangle");
		btnCircleTriangle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				CTGUI gui = new CTGUI();
				JFrame jf = new JFrame();
				jf.setTitle("Test");
				jf.setSize(1280,960);
				jf.setVisible(true);
				jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				jf.getContentPane().add(gui);
				StaticMethods.SortShapes();
				StaticMethods.drawAll();
				StaticMethods.convertAll();
			}
		});
		btnCircleTriangle.setBounds(217, 346, 185, 29);
		frmPatoglushapegui.getContentPane().add(btnCircleTriangle);
		
		JButton btnTriangleRectangle_2 = new JButton("Circle - Rectangle");
		btnTriangleRectangle_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				CRGUI gui = new CRGUI();
				JFrame jf = new JFrame();
				jf.setTitle("Test");
				jf.setSize(1280,960);
				jf.setVisible(true);
				jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				jf.getContentPane().add(gui);
				StaticMethods.SortShapes();
				StaticMethods.drawAll();
				StaticMethods.convertAll();
			}
		});
		btnTriangleRectangle_2.setBounds(217, 301, 185, 29);
		frmPatoglushapegui.getContentPane().add(btnTriangleRectangle_2);
		
		JButton btnTriangleCircle = new JButton("Triangle - Circle");
		btnTriangleCircle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				TCGUI gui = new TCGUI();
				JFrame jf = new JFrame();
				jf.setTitle("Test");
				jf.setSize(1280,960);
				jf.setVisible(true);
				jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				jf.getContentPane().add(gui);
				StaticMethods.SortShapes();
				StaticMethods.drawAll();
				StaticMethods.convertAll();
			}
		});
		btnTriangleCircle.setBounds(217, 256, 185, 29);
		frmPatoglushapegui.getContentPane().add(btnTriangleCircle);
		
		JButton btnTriangleRectangle_1 = new JButton("Triangle - Triangle");
		btnTriangleRectangle_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				TTGUI gui = new TTGUI();
				JFrame jf = new JFrame();
				jf.setTitle("Test");
				jf.setSize(1280,960);
				jf.setVisible(true);
				jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				jf.getContentPane().add(gui);
				StaticMethods.SortShapes();
				StaticMethods.drawAll();
				StaticMethods.convertAll();
			}
		});
		btnTriangleRectangle_1.setBounds(217, 211, 185, 29);
		frmPatoglushapegui.getContentPane().add(btnTriangleRectangle_1);
		
		JButton btnTriangleRectangle = new JButton("Triangle - Rectangle");
		btnTriangleRectangle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				TRGUI gui = new TRGUI();
				JFrame jf = new JFrame();
				jf.setTitle("Test");
				jf.setSize(1280,960);
				jf.setVisible(true);
				jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				jf.getContentPane().add(gui);
				StaticMethods.SortShapes();
				StaticMethods.drawAll();
				StaticMethods.convertAll();
			}
		});
		btnTriangleRectangle.setBounds(217, 166, 185, 29);
		frmPatoglushapegui.getContentPane().add(btnTriangleRectangle);
		
		JButton btnRectangleCircle = new JButton("Rectangle - Circle");
		btnRectangleCircle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				RCGUI gui = new RCGUI();
				JFrame jf = new JFrame();
				jf.setTitle("Test");
				jf.setSize(1280,960);
				jf.setVisible(true);
				jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				jf.getContentPane().add(gui);
				StaticMethods.SortShapes();
				StaticMethods.drawAll();
				StaticMethods.convertAll();
			}
		});
		btnRectangleCircle.setBounds(217, 121, 185, 29);
		frmPatoglushapegui.getContentPane().add(btnRectangleCircle);
		
		JButton btnRectangleTriangle = new JButton("Rectangle - Triangle");
		btnRectangleTriangle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				RTGUI gui = new RTGUI();
				JFrame jf = new JFrame();
				jf.setTitle("Test");
				jf.setSize(1280,960);
				jf.setVisible(true);
				jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				jf.getContentPane().add(gui);
				StaticMethods.SortShapes();
				StaticMethods.drawAll();
				StaticMethods.convertAll();
			}
		});
		btnRectangleTriangle.setBounds(217, 76, 185, 29);
		frmPatoglushapegui.getContentPane().add(btnRectangleTriangle);
		
		JButton btnRectangleRectangle = new JButton("Rectangle - Rectangle");
		btnRectangleRectangle.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				RRGUI gui = new RRGUI();
				JFrame jf = new JFrame();
				jf.setTitle("Test");
				jf.setSize(1280,960);
				jf.setVisible(true);
				jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				jf.getContentPane().add(gui);
				StaticMethods.SortShapes();
				StaticMethods.drawAll();
				StaticMethods.convertAll();
			}
		});
		btnRectangleRectangle.setBounds(217, 31, 185, 29);
		frmPatoglushapegui.getContentPane().add(btnRectangleRectangle);
	}
}
