//uses crt;
var st:string;
        n,x,i,j:longint;
begin
        readln(st);
        n:=length(st);
        x:=trunc(sqrt(n));
        while (n mod x)<>0 do dec(x);
        for i:= 0 to x-1 do
        for j:= 0 to (n div x) -1 do
        write(st[i+j*x+1]);
end.