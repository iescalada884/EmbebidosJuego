----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14.12.2024 15:47:45
-- Design Name: 
-- Module Name: tb - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity tb is
--  Port ( );
end tb;

architecture Behavioral of tb is
    -- Señales para AXI
    signal clk       : std_logic := '0';
    signal reset_n   : std_logic := '0';
    signal awaddr    : std_logic_vector(3 downto 0) := (others => '0');
    signal awvalid   : std_logic := '0';
    signal awready   : std_logic;
    signal wdata     : std_logic_vector(31 downto 0) := (others => '0');
    signal wstrb     : std_logic_vector(3 downto 0) := (others => '1');
    signal wvalid    : std_logic := '0';
    signal wready    : std_logic;
    signal bresp     : std_logic_vector(1 downto 0);
    signal bvalid    : std_logic;
    signal bready    : std_logic := '0';
    signal araddr    : std_logic_vector(3 downto 0) := (others => '0');
    signal arvalid   : std_logic := '0';
    signal arready   : std_logic;
    signal rdata     : std_logic_vector(31 downto 0);
    signal rresp     : std_logic_vector(1 downto 0);
    signal rvalid    : std_logic;
    signal rready    : std_logic := '0';

    -- Señales del periférico
    signal pantalla  : std_logic_vector(7 downto 0);
    signal caracter  : std_logic_vector(3 downto 0);
begin
    clk_gen : process
    begin
        while true loop
            clk <= not clk;
            wait for 10 ns;
        end loop;
    end process;
    
    uut: entity work.disp_v1_0
    generic map (
        C_S00_AXI_DATA_WIDTH => 32,
        C_S00_AXI_ADDR_WIDTH => 4
    )
    port map (
        -- Conexión AXI
        s00_axi_aclk    => clk,
        s00_axi_aresetn => reset_n,
        s00_axi_awaddr  => awaddr,
        s00_axi_awprot  => "000",
        s00_axi_awvalid => awvalid,
        s00_axi_awready => awready,
        s00_axi_wdata   => wdata,
        s00_axi_wstrb   => wstrb,
        s00_axi_wvalid  => wvalid,
        s00_axi_wready  => wready,
        s00_axi_bresp   => bresp,
        s00_axi_bvalid  => bvalid,
        s00_axi_bready  => bready,
        s00_axi_araddr  => araddr,
        s00_axi_arprot  => "000",
        s00_axi_arvalid => arvalid,
        s00_axi_arready => arready,
        s00_axi_rdata   => rdata,
        s00_axi_rresp   => rresp,
        s00_axi_rvalid  => rvalid,
        s00_axi_rready  => rready,
        
        -- Conexión del display
        pantalla        => pantalla,
        caracter        => caracter
    );

    stim_proc: process
    begin
        -- Reset
        reset_n <= '0';
        wait for 50 ns;
        reset_n <= '1';

        -- Escribir en el registro de datos (slv_reg0)
        awaddr <= "0000";  -- Dirección del registro 0
        wdata <= "00001111";  -- Datos para el display
        awvalid <= '1';
        wvalid <= '1';
        wait for 20 ns;
        awvalid <= '0';
        wvalid <= '0';

        -- Escribir en el registro de selección de dígito (slv_reg1)
        awaddr <= "0001";  -- Dirección del registro 1
        wdata <= "00000010";  -- Selección del dígito
        awvalid <= '1';
        wvalid <= '1';
        wait for 20 ns;
        awvalid <= '0';
        wvalid <= '0';

        -- Leer los valores de salida
        wait for 100 ns;
        assert (pantalla = "00001111" and caracter = "0010")
        report "Error: Salida incorrecta" severity failure;

        wait;
    end process;

end Behavioral;
