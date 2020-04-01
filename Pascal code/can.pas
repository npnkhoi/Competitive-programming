uses crt;
var     m,n,du,duong,am,x:longint;
        a,b:array[0..20] of longint;
        f,g:text;
        i: byte;
begin
        assign(f,'can.inp'); assign(g,'can.out');
        reset(f); rewrite(g);
        readln(f,m);
        if m=0 then begin writeln(g,0); writeln(g,0); end
        else
        begin
        ///////////////////////////  doi sang he co so 3
        n:= -1;
        while m>0 do
                begin
                inc(n);
                a[n]:= m mod 3;
                m:= m div 3;
                end;
        //////////////////////////    chuyen thanh cac bit 0,1,-1
        du:= 0;
        for i:= 0 to n do
        begin
                x:= a[i]+du;
                if x=2 then begin a[i]:= -1; du:= 1; end
                else if x=3 then
                        begin a[i]:= 0; du:= 1; end
                        else begin a[i]:= x; du:= 0; end;
        end;
        if du=1 then
                begin inc(n); a[n]:= 1; end;
        /////////////////////////////  tao cac luy thua cua 3
        b[0]:= 1; for i:= 1 to n do b[i]:= b[i-1]*3;
        ////////////////////////////
        duong:= 0; am:= 0;
        for i:= 0 to n do
        begin
                if a[i]>0 then inc(duong);
                if a[i]<0 then inc(am);
        end;
        write(g,am,' ');
        for i:= 0 to n do if a[i]=-1 then write(g,b[i],' ');
        writeln(g);
        write(g,duong,' ');
        for i:= 0 to n do if a[i]=1 then write(g,b[i],' ');
        end;
        close(f); close(g);
end.
