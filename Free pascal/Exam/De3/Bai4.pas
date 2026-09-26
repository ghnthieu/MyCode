Program bai4;
var fi,fo:text;
    m,n:qword;
procedure nhap(var fi:text);
begin
  assign(fi,'tongtich.inp');reset(fi);
end;
procedure xuly(var fo:text);
var tong,tich,t:integer;
begin
  assign(fo,'tongtich.out');rewrite(fo);
  read(fi,m,n);
  tong:=0;
  tich:=1;
  repeat
    t:=n mod 10;
    n:=n div 10;
    tong:=tong+t;
    tich:=tich*t;
    dec(m);
  until m=0;
  writeln(fo,tong);
  write(fo,tich);
  close(fi);
  close(fo);
end;
Begin
  nhap(fi);
  xuly(fo);
End.
