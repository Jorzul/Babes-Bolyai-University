package model;

public class Sfera implements Item{
    private float volume;
    private String type;

    public Sfera() {this(1);}
    public Sfera(float volume){
        this.volume = volume;
        this.type = "Sfera";
    }

    @Override
    public float getVolume() {return this.volume;}
    public String getType() { return this.type; }
}
