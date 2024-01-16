# frozen_string_literal: true

RSpec.describe CHello do
  it "is polite" do
    expect(described_class.hello("Erin")).to eq "Hello, Erin"
  end

  it "is inclusive" do
    expect(described_class.hello).to eq "Hello, World"
  end

  it "can get excited" do
    expect(described_class.hello!("dabidu")).to eq "HELLO, DABIDU!"
  end
end
