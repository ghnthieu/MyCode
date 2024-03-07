Program pt_yn;
uses crt;
type mang=array[1..10,1..10] of integer;
var a:mang;
    n,m:byte;
procedure nhap(var a:mang; var m,n:byte);
var i,j:byte;
begin
  write('nhap so hang: ');readln(m);
  write('nhap so cot: ');readln(n);
  for i:=1 to m do
    for j:=1 to n do
      begin
        write('a[',i,',',j,']=');readln(a[i,j]);
      end;
end;
procedure in_ra(a:mang; m,n:byte);
var i,j:byte;
begin
  for i:=1 to m do
    begin
      for j:=1 to n do
        write(a[i,j]:3);
      writeln;
    end;
end;
procedure ptyn(a:mang; m,n:byte);
var i,j,p:byte;
    min:integer;
    ok:boolean;
begin
  p:=1;
  for i:=1 to m do
    begin
      min:=a[i,1];
      for j:=2 to n do
        if a[i,j]<min then
          begin
            min:=a[i,j];
            p:=j;
          end;
      ok:=true;
      for j:=1 to m do
        if a[i,p]<a[j,p] then
          begin
            ok:=false;
            break;
          end;
    end;
  if ok=true then
    writeln('Vi tri ptyn la: ','a[',i,',',p,']')
  else
    writeln('Khong co phan tu yen ngua');
end;
Begin
  clrscr;
  nhap(a,m,n);
  in_ra(a,m,n);
  ptyn(a,m,n);
  readln
End.