package kanalizacija;

import java.awt.*;

public abstract class Cev extends Kvadrat {
	
	protected Color unutrasnjostCeviBoja  = new Color(204, 204, 204);
	protected Color iviceiUsmerenjeCeviBoja = Color.BLACK;

	public Cev() {
		super(new Color(170, 170, 170));
	}

	@Override
	public void paint(Graphics g) {
		super.paint(g);
		g.setColor(unutrasnjostCeviBoja);
		iscrtajUnutrasnjost(g);
		g.setColor(iviceiUsmerenjeCeviBoja);
		iscrtajIviceiUsmerenje(g);
	}
	
	@Override
	public boolean mozeOznaka() {
		return true;
	}
	
	protected abstract void iscrtajUnutrasnjost(Graphics g);
	
	protected abstract void iscrtajIviceiUsmerenje(Graphics g);
	
}
