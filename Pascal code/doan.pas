uses crt;
var l,r:array[1..1000] of longint;
        n,i,j,ult,dem:longint;
        f,g: text;
procedure input;
begin
        assign(f,'doan.inp');   assign(g,'doan.out');
        reset(f); rewrite(g);
        readln(f,n);
        for i:= 1 to n do readln(f,l[i],r[i]);
end;
procedure swap(var a,b:longint);
var t:longint;
begin
        t:= a; a:=b; b:= t;
end;
procedure sort(t,p:longint);
var i,j,x:longint;
begin
        i:= t; j:= p;
        x:= r[(t+p) div 2];
        repeat
                while (r[i]<x) and (i<=j) do inc(i);
                while (r[j]>x) and (i<=j) do dec(j);
                if i<=j then
                        begin
                                swap(l[i],l[j]); swap(r[i],r[j]);
                                inc(i); dec(j);
                        end;
        until i>j;
        if t<j then sort(t,j);
        if i<p then sort(i,p);
end;

procedure solve;
begin
        ult:= -1001; dem:= 0;

        for i:= 1 to n do
                if l[i]>ult then begin ult:= r[i]; inc(dem); end;
end;
begin
        input;
        sort(1,n);
        solve;
        writeln(g,dem);
        close(f);    close(g);
end.
