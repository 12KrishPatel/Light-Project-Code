export type Design = {
  id: string;
  name: string;
  category: string;
  pixels: string[];
};

export type ConnectionState = "disconnected" | "connecting" | "connected" | "unsupported";
