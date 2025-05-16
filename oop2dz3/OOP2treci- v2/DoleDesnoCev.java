package kanalizacija;

import java.awt.Graphics;
import java.awt.Graphics2D;

public class DoleDesnoCev extends LevoDoleCev {
	
	private int x, y;

	protected void iscrtajUnutrasnjost(Graphics g) {
		x = getX();
		y = getY();
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x, y + getHeight() - 1);
		g2.rotate(3*Math.PI/2.0);
		super.iscrtajUnutrasnjost(g2);
		g2.translate(x, y - getHeight() + 1);
	}

	@Override
	protected void iscrtajIviceiUsmerenje(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x, y + getHeight() - 1);
		super.iscrtajIvice(g2);
		super.iscrtajUsmerenje(g2);
		g2.translate(x, y - getHeight() + 1);
	}
	
}
