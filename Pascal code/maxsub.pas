uses math;
var l:array[0..100,0..100] of byte;
        s1,s2,s:string;
        m,n,i,j:byte;
        f:text;
procedure input;
begin
        assign(f,'maxsub.inp');
        reset(f);
        readln(f,s1);
        readln(f,s2);
        close(f);
end;
procedure dp;
begin
        m:= length(s1); n:= length(s2);
        for i:= 0 to m do l[i,0]:= 0;
        for j:= 0 to n do l[0,j]:= 0;
        for i:= 1 to m do
        for j:= 1 to n do
                if s1[i]=s2[j] then l[i,j]:= l[i-1,j-1]+1
                else l[i,j]:= max(l[i-1,j],l[i,j-1]);

end;
procedure trace;
begin
        i:= m; j:= n; s:= '';
        repeat
                if s1[i]=s2[j] then
                        begin
                                s:= s1[i]+s;
                                dec(i);dec(j);
                        end
                else if l[i-1,j]>l[i,j-1] then dec(i)
                else dec(j);
                until (i=0) or (j=0);
end;
procedure output;
begin
        writeln('Max length: ',l[m,n]);
        writeln(s);
        readln;
end;
begin
        input;
        dp;
        trace;
        output;
end.