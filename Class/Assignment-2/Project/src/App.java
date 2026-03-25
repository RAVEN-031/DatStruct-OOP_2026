public class App {
    public static void main(String[] args) throws Exception {
        //Finally, time to work
        Espresso order1 = new Americano(3, "Robusta", false, true);
        Espresso order2 = new Cappuccino(4, "Arabica", false, false, "Oat");

        System.out.println("Order 1");
        order1.showComposition();
        order1.brewCoffee();
        order1.printPrice();
        System.out.println("Order 2");
        order2.showComposition();
        order2.brewCoffee();
        order2.printPrice();
    }
}

abstract class Espresso {
    //PLEASE I AM TIRED OF DOING ASSIGNMENTS I AM FAMISHSED I NEED FOOD, attributes, btw
    private String name;
    private int price;
    private String bean;
    private boolean decaf;
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
    public void brewCoffee() {System.out.println("Brewing " + getName() + " Ice: " + getIce() + " Bean: " + getBean() + " Decaf: " + getDecaf());}
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
