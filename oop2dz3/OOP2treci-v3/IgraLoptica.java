package igra;

import java.awt.*;
import java.awt.event.*;

public class IgraLoptica extends Frame {
	
	private Scena scena;
	
	private Igrac igrac;
	
	public IgraLoptica() {
		setBounds(700, 200, 500, 700);
		setResizable(false);
		setTitle("Loptica");
		
		populateWindow();
		
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				scena.zavrsi();
				dispose();
			}
		});
		
		setVisible(true);
		igrac = new Igrac(scena, 40, 10);
		int x = 2, y = 2;
		int sirina = scena.getWidth()/5 - 2, visina = sirina/4;
		for(int i = 0; i < 15; i++) {
			if(i % 5 == 0 && i != 0) {
				y += visina + 2;
				x = 2;
			}
			Cigla cigla = new Cigla(scena, x, y, sirina, visina, 100);
			x += sirina + 2;
			scena.repaint();
		}
		scena.kreni();
	}
	
	private void populateWindow() {
		scena = new Scena();
		add(scena);
		scena.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				igrac.ispaliLopticu(Color.GREEN);
				scena.repaint();
			}
		});
		scena.addKeyListener(new KeyAdapter() {

			@Override
			public void keyPressed(KeyEvent e) {
				if(e.getKeyCode() == KeyEvent.VK_LEFT) {
					igrac.pomeri(-10, 0);
				}else if(e.getKeyCode() == KeyEvent.VK_RIGHT) {
					igrac.pomeri(10, 0);
				}
				scena.repaint();
			}
		});
	}

	public static void main(String[] args) {
		new IgraLoptica();
	}
}
