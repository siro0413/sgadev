#pragma once

class Camera
{
public:
	Camera();
	virtual ~Camera();
	
	D3DXMATRIX View() { return view; }
	D3DXVECTOR2 Position() { return position; }

	virtual void Update();
	
	
	


private:
	D3DXMATRIX view;

protected:
	D3DXVECTOR2 position;
		
};

