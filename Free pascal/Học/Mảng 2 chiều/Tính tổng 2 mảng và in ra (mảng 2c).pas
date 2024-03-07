Program mang2c;
uses crt;
type mang=array[1..10,1..10] of integer;
var a,b:mang;
    n,m:byte;
procedure nhap(var a,b:mang; var m,n:byte);
var i,j:byte;
begin
  write('Nhap so hang: ');readln(m);
  write('Nhap so cot: ');readln(n);
  for i:=1 to m do
    for j:=1 to n do
      begin
        a[i,j]:=random(10);
        b[i,j]:=random(10);
      end;
end;
procedure in_ra(a,b:mang; m,n:byte);
var i,j:byte;
begin
  for i:=1 to m do
    begin
      for j:=1 to n do
        write(a[i,j],' ');
      writeln;
    end;
  writeln('-------------------------');
  for i:=1 to m do
    begin
      for j:=1 to n do
        write(b[i,j],' ');
      writeln;
    end;
end;
procedure cong_mc(a,b:mang; m,n:byte);
var i,j:byte;
    c:mang;
begin
  writeln('-----------------------');
  for i:=1 to m do
    for j:=1 to n do
      c[i,j]:=a[i,j]+b[i,j];
  for i:=1 to m do
    begin
      for j:=1 to n do
        write(c[i,j],' ');
      writeln;
    end;
end;
Begin
  clrscr;
  nhap(a,b,m,n);
  in_ra(a,b,m,n);
  cong_mc(a,b,m,n);
  readln
End.