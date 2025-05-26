public class Rectangle implements Shape{
    private double width;
    private double height;

    public Rectangle(double width, double height){
        this.width=width;
        this.height=height;
    }
    public double getArea(){
        return width*height;
    }

    public double getPerimeter(){
        return 2*width + 2*height;
    }

    public static void main(String[] args){
        Rectangle r1=new Rectangle(4, 3);
        System.out.print(r1.getArea());
        System.out.print(r1.getPerimeter());
    }
}
