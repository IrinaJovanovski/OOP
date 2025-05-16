package kanalizacija;

import java.awt.Color;
import java.awt.Graphics;

public class Zid extends Kvadrat {

	public Zid() {
		super(new Color(170, 170, 170));
	}
	
	@Override
	public void paint(Graphics g) {
		super.paint(g);
	}

	@Override
	public boolean mozeOznaka() {
		return true;
	}
	
}
