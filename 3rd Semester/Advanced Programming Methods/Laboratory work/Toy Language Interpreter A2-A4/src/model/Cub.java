package model;

public class Cub implements Item{
    private float volume;
    private String type;

    public Cub(){
        this(1);
    }
    public Cub(float volume){
        this.volume = volume;
        this.type = "Cub";
    }
    @Override
    public float getVolume() {
        return this.volume;
    }
    public String getType() { return this.type; }
}
