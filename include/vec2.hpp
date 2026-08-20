class vec2
{
  
  public:

  float m_x;
  float m_y;
  vec2();
  vec2(const float &x, const float &y);
  ~vec2();
  static float dotProduct(const vec2 &x, const vec2 &y);
  static float crossProduct(const vec2 &x, const vec2 &y);
  static float getDistance(const vec2 &a, const vec2 &b);
};