/*
** core_perlin.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 19 14:08:31 2016 Arthur Josso
** Last update Fri Feb 19 17:07:25 2016 Arthur Josso
*/

float	grad(int h, float x, float y, float z)
{
  float	u;
  float	v;

  h &= 0x0f;
  if (h < 0b1000)
    u = x;
  else
    u = y;
  if (h == 0b1110 || h == 0b1100)
    v = x;
  else if (h < 0b0100)
    v = y;
  else
    v = z;
  if ((h & 0b0001) != 0)
    u *= -1;
  if ((h & 0b0010) != 0)
    v *= -1;
  return (u + v);
}

float	lerp(float x, float a, float b)
{
  return (a + x * (b - a));
}

float	fade(float x)
{
  return (x * x * x * (x * (6 * x - 15) + 10));
}
