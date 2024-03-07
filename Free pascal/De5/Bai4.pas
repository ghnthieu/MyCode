Program bai4;
var n:byte;
    a:array[1..100] of integer;
procedure doicho(var a,b:integer);
var t:integer;
begin
  t:=a;
  a:=b;
  b:=t;
end;
procedure xuly;
var i,j:byte;
    t:integer;
    fi,fo:text;
begin
  assign(fi,'Dayso.inp');reset(fi);
  assign(fo,'Dayso.out');rewrite(fo);
  readln(fi,n);
  for i:=1 to n do
    read(fi,a[i]);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i]>a[j] then
        doicho(a[i],a[j]);
  for i:=1 to n do
    write(fo,a[i],' ');
  writeln(fo);
  for i:=1 to n do
    if a[i+1]>a[i] then
      begin
        t:=a[i+1];
        break;
      end;
  writeln(fo,t);
  for i:=n downto 1 do
    if a[i-1]<a[i] then
      begin
        t:=a[i-1];
        break;
      end;
  writeln(fo,t);
  close(fi);
  close(fo);
end;
Begin
  xuly;
End.
