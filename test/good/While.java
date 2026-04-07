class While {
    public static void main(String[] args) {
        System.out.println(new WhileAux().w());
    }
}

class WhileAux {
    public int w(){
        int i;
        int res;
        i = 0;
        res = 0;
        while (i < 10) {
            res = res + 2;
            i = i + 1;
        }
        if (res == 20){
            System.out.println(1);
        }else{
            System.out.println(0);
        }
        return res;
    }
}
