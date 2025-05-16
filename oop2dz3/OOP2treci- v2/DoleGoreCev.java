package kanalizacija;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;

public class DoleGoreCev extends LevoDesnoCev {

	private int x, y;
	
	@Override
	protected void iscrtajUnutrasnjost(Graphics g) {
		x = getX();
		y = getY();
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x, y + getHeight() - 1);
		g2.rotate(3*Math.PI/2);
		super.iscrtajUnutrasnjost(g2);
		g2.translate(x, y - getHeight() + 1);
		
	}

	@Override
	protected void iscrtajIviceiUsmerenje(Graphics g) {
		int x = getX();
		int y = getY();
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x, y + getHeight() - 1);
		super.iscrtajIviceiUsmerenje(g2);
		g2.translate(x, y - getHeight() + 1);
	}
	
}
