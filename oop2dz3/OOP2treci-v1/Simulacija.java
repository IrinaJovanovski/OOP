package simulacija;

import java.awt.*;
import java.awt.event.*;

public class Simulacija extends Frame {
	
	private Scena scena;
	
	public Simulacija() {
		setBounds(700, 200, 500, 500);
		setResizable(false);
		setTitle("Simulacija");
		
		populateWindow();
		
		/*addComponentListener(new ComponentAdapter() {
			@Override
			public void componentResized(ComponentEvent e) {
				scena.repaint();
				pack();
			}
		});*/
		
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				scena.zavrsi();
				dispose();
			}
		});
		
		setVisible(true);
	}
	
	private void populateWindow() {
		scena = new Scena(this);
		add(scena);
		
		scena.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				if(e.getButton() == MouseEvent.BUTTON1) { //button3 - desni; button1 - levi
					scena.dodaj(new Kamencic(e.getX(),e.getY()));
				}
			}
		});
		
		scena.addKeyListener(new KeyAdapter() {
			
			@Override
			public void keyPressed(KeyEvent e) {
				if(e.getKeyCode() == KeyEvent.VK_ESCAPE) {
					scena.zavrsi();
					dispose();
				}else if(e.getKeyCode() == KeyEvent.VK_SPACE) {
					if(scena.radi()) {
						scena.pauziraj();
					}else {
						scena.nastavi();
					}
				}
			}
		});
	}

	public static void main(String[] args) {
		new Simulacija();
	}
}
