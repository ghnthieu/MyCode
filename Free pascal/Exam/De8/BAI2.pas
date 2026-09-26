Program bai2;
var h1,m1,h2,m2:byte;
procedure xuly;
var fi,fo:text;
    mi:integer;
    mo:longint;
begin
  assign(fi,'BAI2.INP');reset(fi);
  assign(fo,'BAI2.OUT');rewrite(fo);
  readln(fi,h1,m1);
  read(fi,h2,m2);
  mi:=(h2*60+m2)-(h1*60+m1);
  if mi<=60 then
    mo:=mi*80
  else
    if mi<=120 then
      mo:=60*80+(mi-60)*50
    else
      mo:=60*80+60*50+(mi-120)*30;
   write(fo,mo);
   close(fi);
   close(fo);
end;
Begin
  xuly;
End.
