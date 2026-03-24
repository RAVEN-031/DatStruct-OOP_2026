public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
    }
}

abstract class Espresso {
    //PLEASE I AM TIRED OF DOING ASSIGNMENTS I AM FAMISHSED I NEED FOOD, attributes, btw
    private String name;
    private int price;
    protected String bean;
    protected boolean decaf;
    private boolean ice;
    //Construct deez nuts
    Espresso(String a,int b, String c, boolean d, boolean e) {
        this.name=a;
        this.price=b;
        this.bean=c;
        this.decaf=d;
        this.ice=e;
    }
    //Enough with getters, please try getting a girlfriend instead
    public String getName() {return name;}
    public int getPrice() {return price;}
    public String getBean() {return bean;}
    public boolean getDecaf() {return decaf;}
    public boolean getIce() {return ice;}
    //googlesearch:Methods on how to get invited into the epstein island
    public void printPrice() {System.out.println("Price: " + getPrice());}
    public void brewCoffee() {System.out.println("Brewing " + getName());}
    abstract void showComposition();
}

class Americano extends Espresso {
    //MORE CONSTRUSHAfuabukfajswhjbJHBwhabsfhba
    Americano(int b, String c, boolean d, boolean e){
        super("Americano", b, c, d, e);
    }
    //OVERRIDE? KASANE TETO MENTIONED???
    @Override
    void showComposition() {System.out.println(getName() + " contains 30% espresso and 60% water");}
}

class Cappuccino extends Espresso {
    //Chat, I'm losing it
    private String milk;
    //DANG IT, I SHOULD'VE MADE ICE AN ATTRIBUTE IN PARENT CLASS
    //Well crap, I ended up fixing it, sucks
    Cappuccino(int b, String c, boolean d, boolean e, String f) {
        super("Cappuccino", b, c, d, e);
        this.milk=f;
    }
    //Now I really am losing it
    public String getMilk() {return milk;}
    //Use AI? Sorry, I have brain
    @Override
    void showComposition() {System.out.println(getName() + " contains 33% espresso, 33% steamed milk, and 33% foam");}

}
//FINALLY, I'LL EAT BEFORE MAKING THE MAIN CLASS