public class App {
    public static void main(String[] args) throws Exception {
        //Object instantiation
        Firearm rifle1 = new AutoRifle("M4A1", "United States", 30, "5.56x45mm", 700);
        Firearm rifle2 = new AutoRifle("HK416", "Germany", 30, "5.56x45mm", 850);
        Firearm pistol1 = new Pistol("USP45", "Germany", 12, ".45 ACP", 600);
        Firearm shotgun1 = new PumpActionShotgun("Mossberg 500", "United States", 8, "12 Gauge Shells", 1);
        
        //Not gonna deal with normal program that handles input output, this will only test the OOP
        System.out.println("Calling methods for object rifle1");
        rifle1.inspect();
        rifle1.shoot();
        rifle1.reload();
        System.out.println("\nCalling methods for object rifle2");
        rifle2.inspect();
        rifle2.shoot();
        rifle2.reload();
        System.out.println("\nCalling methods for object pistol1");
        pistol1.inspect();
        pistol1.shoot();
        pistol1.reload();
        System.out.println("\nCalling methods for object shotgun1");
        shotgun1.inspect();
        shotgun1.shoot();
        shotgun1.reload();
    }
}

abstract class Firearm {

    //Attributes
    protected String name;
    protected String origins;
    protected int capacity;
    protected String calibre;
    protected int firerate;

    //Constructor
    public Firearm(String name, String origins, int capacity, String calibre, int firerate){
        this.name = name;
        this.origins = origins;
        this.capacity = capacity;
        this.calibre = calibre;
        this.firerate = firerate;
    }

    //Setter
    public void setName(String name){
        this.name = name;
    }
    public void setOrigins(String country){
        this.origins = country;
    }
    public void setCapacity(int capacity){
        this.capacity = capacity;
    }
    public void setCalibre(String calibre){
        this.calibre = calibre;
    }
    public void setFirerate(int firerate){
        this.firerate = firerate;
    }
    
    //getter
    public String getName(){
        return this.name;
    }
    public String getOrigins(){
        return this.origins;
    }
    public int getCapacity(){
        return this.capacity;
    }
    public String getCalibre(){
        return this.calibre;
    }
    public int getFirerate(){
        return this.firerate;
    }

    //Methods
    abstract void shoot();
    public void reload(){
        System.out.println("Gun reloaded with " + capacity + " rounds of " + calibre);
    }
    public void inspect(){
        System.out.println("Name: " + getName() + "\nOrigins: " + getOrigins() + "\nCapacity: " + getCapacity() + "\nCalibre: " + getCalibre() + "\nFirerate: " + getFirerate() + " RPM");
    }

}


class AutoRifle extends Firearm{
    //Constructor
    public AutoRifle(String name, String origins, int capacity, String calibre, int firerate){
        super(name, origins, capacity, calibre, firerate);
    }
    @Override
    void shoot(){
        System.out.println(getName() + " shoots continuously with firerate of " + getFirerate() + " RPM");
    }
}

class Pistol extends Firearm{

    //Constructor
    public Pistol(String name, String origins, int capacity, String calibre, int firerate){
        super(name, origins, capacity, calibre, firerate);
    }
    @Override
    void shoot(){
        System.out.println(getName() + " shoots one round per trigger pull");
    }
}

class PumpActionShotgun extends Firearm{
    public PumpActionShotgun(String name, String origins, int capacity, String calibre, int firerate){
        super(name, origins, capacity, calibre, firerate);
    }
    @Override
    void shoot(){
        System.out.println(getName() + " shoots one shell then gets pumped");
    }
}