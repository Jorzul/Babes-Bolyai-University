package model;

public class Cilindru implements Item{
    private float volume;
    private String type;

    public Cilindru(){
        this(1);
    }
    public Cilindru(float volume){
        this.volume = volume;
        this.type = "Cilindru";
    }

    @Override
    public float getVolume() {return this.volume;}
    public String getType() {return this.type;}
}
