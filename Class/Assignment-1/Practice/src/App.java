public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Jawa!");
    }
}

abstract class Firearm {

    //Attributes
    protected String origins;
    protected int capacity;
    protected String calibre;
    protected int firerate;

    //Constructor
    public Firearm(String origins, int capacity, String calibre, int firerate){
        this.origins = origins;
        this.capacity = capacity;
        this.calibre = calibre;
        this.firerate = firerate;
    }

    //Setter
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
    
}