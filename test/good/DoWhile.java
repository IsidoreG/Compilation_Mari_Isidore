class DoWhile {
    public static void main(String[] args) {
        System.out.println(new DoWhileAux().w());
    }
}

class DoWhileAux {
    public int w(){
        int i;
        int res;
        i = 0;
        res = 0;
        do {
            res = res + 2;
            i = i + 1;
        } while(i < 10);
        
        if (res == 20){
            System.out.println(1);
        }else{
            System.out.println(0);
        }
        return res;
    }
}
