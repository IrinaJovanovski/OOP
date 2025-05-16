package kanalizacija;

import java.awt.Graphics;
import java.awt.Graphics2D;

public class GoreDoleCev extends LevoDesnoCev {
	
	private int x, y;

	@Override
	protected void iscrtajUnutrasnjost(Graphics g) {
		x = getX();
		y = getY();
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x + getWidth() - 1, y);
		g2.rotate(Math.PI/2);
		super.iscrtajUnutrasnjost(g2);
		g2.translate(x - getWidth() + 1, y);
	}

	@Override
	protected void iscrtajIviceiUsmerenje(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x + getWidth() - 1, y);
		super.iscrtajIviceiUsmerenje(g2);
		g2.translate(x - getWidth() + 1, y);
	}

}
