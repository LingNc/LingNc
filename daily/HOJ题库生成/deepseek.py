from openai import OpenAI
# for backward compatibility, you can still use `https://api.deepseek.com/v1` as `base_url`.
client = OpenAI(api_key="sk-9011b751ed194e12bc0876ed3256f172", base_url="https://api.deepseek.com")

response = client.chat.completions.create(
    model="deepseek-coder",
    messages=[
        {"role": "system", "content": "You are a helpful assistant"},
        {"role": "user", "content": "Hello"},
  ],
    max_tokens=1024,
    temperature=0.7,
    stream=False
)

print(response.choices[0].message.content)